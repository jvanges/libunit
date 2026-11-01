#ifndef TESTS_BONUS_H
# define TESTS_BONUS_H

/*
** Prototypes des tests qui valident chaque fonctionnalite bonus du
** framework, comme l'exige le sujet : chaque feature est accompagnee
** d'une routine qui la teste reellement.
*/
int	sigabrt_test(void);
int	sigfpe_test(void);
int	sigpipe_test(void);
int	sigill_test(void);
int	timeout_test(void);
int	stdout_test(void);

/* Launcher de la routine bonus ("fonction testee" : BONUS) */
int	bonus_launcher(void);

#endif
