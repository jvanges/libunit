/* ************************************************************************** */
/*                                                                            */
/*  launch_tests_bonus.c : orchestrateur avec couleurs, timeout et journal    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit_bonus.h"
#include <unistd.h>

/*
** write_nb : ecrit un entier positif dans le journal (chiffre par chiffre,
** car write() ne fait aucune conversion, contrairement a printf/dprintf).
*/
static void	write_nb(int fd, int n)
{
	char	c;

	if (n >= 10)
		write_nb(fd, n / 10);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

/*
** log_summary : ecrit le bilan "X/Y tests checked" dans le journal.
*/
static void	log_summary(int fd, int ok, int total)
{
	write_nb(fd, ok);
	write(fd, "/", 1);
	write_nb(fd, total);
	write(fd, " tests checked\n", 15);
}

/*
** launch_tests_bonus : identique a launch_tests() de la partie obligatoire,
** avec en plus par test : couleurs ANSI, timeout via alarm(), capture de
** stdout, detection etendue des signaux, et journalisation en ligne a ligne
** dans <function_name>.log.
** Meme contrat de retour : 0 si succes complet, -1 sinon.
*/
int	launch_tests_bonus(t_unit_test **list, char *function_name)
{
	t_unit_test	*cur;
	int			total;
	int			success;
	int			status;
	int			log_fd;

	log_fd = open_log(function_name);
	cur = *list;
	total = 0;
	success = 0;
	while (cur)
	{
		status = exec_test_bonus(cur);
		print_result_bonus(function_name, cur->name, status);
		if (log_fd != -1)
			log_line(log_fd, function_name, cur->name, status);
		total++;
		if (status == ST_OK)
			success++;
		cur = cur->next;
	}
	clear_tests(list);
	print_summary(success, total);
	if (log_fd != -1)
	{
		log_summary(log_fd, success, total);
		close(log_fd);
	}
	if (success == total)
		return (0);
	return (-1);
}
