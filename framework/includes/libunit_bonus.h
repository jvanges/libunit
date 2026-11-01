#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

# include "libunit.h"

/*
** Delai maximum d'execution d'un test, en secondes.
** Apres ce delai, le fils recoit SIGALRM et le test est rapporte
** comme [TIMEOUT] par le pere.
*/
# define TEST_TIMEOUT 5

/*
** Codes de statut supplementaires geres par la partie bonus.
** Ils demarrent a 100 pour ne jamais entrer en conflit avec
** l'enum e_status de la partie obligatoire.
*/
enum e_status_bonus
{
	ST_B_ABRT = 100,    /* SIGABRT : abort() appele dans le test      */
	ST_B_FPE,           /* SIGFPE  : erreur arithmetique (division 0) */
	ST_B_PIPE,          /* SIGPIPE : ecriture sur un tube ferme       */
	ST_B_ILL,           /* SIGILL  : instruction machine illegale     */
	ST_B_TIMEOUT        /* SIGALRM : depassement du timeout           */
};

/* ------------- API publique bonus --------------------------------------- */

int		launch_tests_bonus(t_unit_test **list, char *function_name);

/* ------------- Fonctions internes bonus --------------------------------- */

int		exec_test_bonus(t_unit_test *test);
void	print_result_bonus(char *function_name, char *test_name, int status);
int		open_log(char *function_name);
void	log_line(int fd, char *function_name, char *test_name, int status);
char	*label_for_status(int status);

#endif
