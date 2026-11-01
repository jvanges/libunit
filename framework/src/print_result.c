/* ************************************************************************** */
/*                                                                            */
/*  print_result.c : affichage des resultats au format impose                 */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

/*
** print_status : traduit un code e_status en etiquette textuelle.
** Syntaxe du sujet : OK / KO / SIGSEGV / SIGBUS.
*/
static void	print_status(int status)
{
	if (status == ST_OK)
		lu_putstr("[OK]");
	else if (status == ST_KO)
		lu_putstr("[KO]");
	else if (status == ST_SEGV)
		lu_putstr("[SEGV]");
	else if (status == ST_BUS)
		lu_putstr("[BUSERR]");
	else
		lu_putstr("[UNKNOWN]");
}

/*
** print_result : affiche une ligne de resultat selon le format du sujet :
**   [fonction testee]:[nom du test]:[statut]
** exemple : STRLEN: Basic test : [OK]
*/
void	print_result(char *function_name, char *test_name, int status)
{
	lu_putstr(function_name);
	lu_putstr(": ");
	lu_putstr(test_name);
	lu_putstr(" : ");
	print_status(status);
	lu_putstr("\n");
}

/*
** print_summary : bilan final de la routine, exige par le sujet :
** le nombre de tests reussis suivi du nombre total de tests.
*/
void	print_summary(int ok, int total)
{
	lu_putnbr(ok);
	lu_putstr("/");
	lu_putnbr(total);
	lu_putstr(" tests checked\n");
}
