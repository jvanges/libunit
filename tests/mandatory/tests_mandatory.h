#ifndef TESTS_MANDATORY_H
# define TESTS_MANDATORY_H

/*
** Prototypes des tests obligatoires exiges par le sujet :
** un vrai OK, un vrai KO, un vrai SIGSEGV et un vrai SIGBUS.
** Chaque fonction suit le prototype impose : int f(void),
** retourne 0 si succes, -1 sinon.
*/
int	ok_test(void);
int	ko_test(void);
int	sigsegv_test(void);
int	sigbus_test(void);

/* Launcher de la routine ("fonction testee" : DUMMY) */
int	mandatory_launcher(void);

#endif
