/* ************************************************************************** */
/*                                                                            */
/*  exec_test.c : execution d'un test dans un processus fils                  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/*
** decode_status : traduit le statut brut rendu par wait() en code e_status.
** - le fils a appele exit()   -> on lit son code de retour (0=OK, sinon KO)
** - le fils a ete tue par un signal -> on identifie SIGSEGV et SIGBUS,
**   comme l'exige la partie obligatoire du sujet.
*/
static int	decode_status(int status)
{
	int	sig;

	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (ST_OK);
		return (ST_KO);
	}
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGSEGV)
			return (ST_SEGV);
		if (sig == SIGBUS)
			return (ST_BUS);
	}
	return (ST_OTHER);
}

/*
** exec_test : le coeur du framework.
** fork() cree un fils qui execute la fonction de test puis exit() avec sa
** valeur de retour. Si le test crash (segfault, bus error...), c'est le
** FILS qui meurt : le pere recupere la cause via wait() et la routine
** continue avec les tests suivants, comme l'exige le sujet
** ("execute a series of tests one after the other without interruption").
** Note : exit(-1) donne un code 255 (8 bits), toujours != 0 -> KO.
*/
int	exec_test(t_unit_test *test)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (ST_OTHER);
	if (pid == 0)
		exit(test->func());
	if (wait(&status) == -1)
		return (ST_OTHER);
	return (decode_status(status));
}
