/* ************************************************************************** */
/*                                                                            */
/*  print_result_bonus.c : affichage colore des resultats                     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit_bonus.h"

/*
** label_for_status : associe un code de statut a son etiquette.
** Partagee entre l'affichage colore et l'ecriture du fichier .log.
*/
char	*label_for_status(int status)
{
	if (status == ST_OK)
		return ("OK");
	if (status == ST_KO)
		return ("KO");
	if (status == ST_SEGV)
		return ("SEGV");
	if (status == ST_BUS)
		return ("BUSERR");
	if (status == ST_B_ABRT)
		return ("ABORT");
	if (status == ST_B_FPE)
		return ("FPE");
	if (status == ST_B_PIPE)
		return ("SIGPIPE");
	if (status == ST_B_ILL)
		return ("ILL");
	if (status == ST_B_TIMEOUT)
		return ("TIMEOUT");
	return ("UNKNOWN");
}

/*
** print_colored : affiche l'etiquette avec un code couleur ANSI.
**   vert    -> [OK]
**   rouge   -> [KO]
**   magenta -> tout signal (crash, timeout...)
** Les sequences \033[...m sont de simples caracteres emis via write().
*/
static void	print_colored(int status, char *label)
{
	if (status == ST_OK)
		lu_putstr("\033[32m");
	else if (status == ST_KO)
		lu_putstr("\033[31m");
	else
		lu_putstr("\033[35m");
	lu_putstr("[");
	lu_putstr(label);
	lu_putstr("]");
	lu_putstr("\033[0m\n");
}

/*
** print_result_bonus : meme format de ligne que la partie obligatoire,
** mais avec l'etiquette coloree.
*/
void	print_result_bonus(char *function_name, char *test_name, int status)
{
	lu_putstr(function_name);
	lu_putstr(": ");
	lu_putstr(test_name);
	lu_putstr(" : ");
	print_colored(status, label_for_status(status));
}
