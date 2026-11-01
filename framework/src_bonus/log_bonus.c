/* ************************************************************************** */
/*                                                                            */
/*  log_bonus.c : journalisation des resultats dans <fonction>.log            */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** build_log_name : construit le nom "<function_name>.log" impose par le sujet.
*/
static char	*build_log_name(char *function_name)
{
	char	*name;
	int		len;
	int		i;

	len = 0;
	while (function_name[len])
		len++;
	name = malloc(len + 5);
	if (!name)
		return (NULL);
	i = -1;
	while (++i < len)
		name[i] = function_name[i];
	name[len] = '.';
	name[len + 1] = 'l';
	name[len + 2] = 'o';
	name[len + 3] = 'g';
	name[len + 4] = '\0';
	return (name);
}

/*
** open_log : cree (ou ecrase) le fichier de log de la routine.
** open/write/close sont utilises volontairement plutot qu'un flux
** bufferise : chaque ligne est ecrite immediatement sur le disque, donc
** le journal reste exploitable meme si un test ulterieur corrompt
** la memoire du processus. Retourne -1 si le fichier est inaccessible
** (la routine continue alors sans journaliser, jamais de crash).
*/
int	open_log(char *function_name)
{
	char	*name;
	int		fd;

	name = build_log_name(function_name);
	if (!name)
		return (-1);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(name);
	return (fd);
}

/*
** log_line : ecrit une ligne de resultat (sans couleur) dans le journal.
*/
void	log_line(int fd, char *function_name, char *test_name, int status)
{
	int	len;

	len = 0;
	while (function_name[len])
		len++;
	write(fd, function_name, len);
	write(fd, ": ", 2);
	len = 0;
	while (test_name[len])
		len++;
	write(fd, test_name, len);
	write(fd, " : [", 4);
	len = 0;
	while (label_for_status(status)[len])
		len++;
	write(fd, label_for_status(status), len);
	write(fd, "]\n", 2);
}
