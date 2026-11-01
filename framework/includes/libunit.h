#ifndef LIBUNIT_H
# define LIBUNIT_H

/* NULL est defini ici : les launchers initialisent leur liste a NULL. */
# include <stddef.h>

/*
** Codes de statut renvoyes par l'execution d'un test.
** Ils servent a traduire le resultat brut de wait() en une
** etiquette affichable : [OK], [KO], [SEGV], [BUSERR]...
*/
enum e_status
{
	ST_OK,      /* exit(0)              : le test a reussi              */
	ST_KO,      /* exit(code != 0)      : le test a echoue              */
	ST_SEGV,    /* mort par SIGSEGV     : faute de segmentation         */
	ST_BUS,     /* mort par SIGBUS      : erreur de bus                 */
	ST_OTHER    /* autre signal ou erreur interne (partie obligatoire)  */
};

/*
** Maillon de la liste chainee qui stocke une routine de tests.
** name : nom du test (duplique, libere par le framework)
** func : pointeur sur la fonction de test, prototype impose par le sujet :
**        int (*f)(void) — retourne 0 si succes, -1 sinon.
*/
typedef struct s_unit_test
{
	char				*name;
	int					(*func)(void);
	struct s_unit_test	*next;
}	t_unit_test;

/* ------------- API publique du framework -------------------------------- */

void	load_test(t_unit_test **list, char *name, int (*func)(void));
int		launch_tests(t_unit_test **list, char *function_name);

/* ------------- Fonctions internes (utilisees entre modules) ------------- */

int		exec_test(t_unit_test *test);
void	clear_tests(t_unit_test **list);
void	print_result(char *function_name, char *test_name, int status);
void	print_summary(int ok, int total);
void	lu_putstr(const char *s);
void	lu_putnbr(int n);

#endif
