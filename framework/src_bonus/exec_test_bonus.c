/* ************************************************************************** */
/*                                                                            */
/*  exec_test_bonus.c : execution d'un test avec les fonctionnalites bonus    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit_bonus.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** child_routine : prepare l'environnement du fils AVANT de lancer le test.
**
** 1) Redirection de stdout vers /dev/null (open + dup2) :
**    la fonction testee peut donc utiliser write(1, ...) librement, son
**    texte est avale par /dev/null et ne pollue pas le rapport du framework
**    (bonus "support for functions writing on the standard output").
**
** 2) alarm(TEST_TIMEOUT) : le fils programme son propre reveil. S'il est
**    encore vivant a l'expiration, il recoit SIGALRM et meurt -> le pere
**    le rapporte [TIMEOUT]. Pas besoin de kill() (interdit par le sujet)
**    et pas de zombie : le pere attend toujours son fils avec wait().
**
** Fonctions externes utilisees (toutes autorisees en bonus, a justifier) :
** open/dup2/close pour la capture de stdout, alarm() pour le timeout.
*/
static void	child_routine(t_unit_test *test)
{
	int	devnull;

	devnull = open("/dev/null", O_WRONLY);
	if (devnull != -1)
	{
		dup2(devnull, STDOUT_FILENO);
		close(devnull);
	}
	alarm(TEST_TIMEOUT);
	exit(test->func());
}

/*
** map_signal : associe un numero de signal a un code de statut affichable.
** La partie bonus couvre tous les signaux proposes par le sujet :
** SIGABRT, SIGFPE, SIGPIPE, SIGILL, plus SIGALRM qui materialise le timeout.
*/
static int	map_signal(int sig)
{
	if (sig == SIGSEGV)
		return (ST_SEGV);
	if (sig == SIGBUS)
		return (ST_BUS);
	if (sig == SIGABRT)
		return (ST_B_ABRT);
	if (sig == SIGFPE)
		return (ST_B_FPE);
	if (sig == SIGPIPE)
		return (ST_B_PIPE);
	if (sig == SIGILL)
		return (ST_B_ILL);
	if (sig == SIGALRM)
		return (ST_B_TIMEOUT);
	return (ST_OTHER);
}

/*
** exec_test_bonus : meme logique que la partie obligatoire
** (fork + wait), mais avec l'environnement bonus prepare dans le fils
** et une table de signaux etendue cote pere.
*/
int	exec_test_bonus(t_unit_test *test)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (ST_OTHER);
	if (pid == 0)
		child_routine(test);
	if (wait(&status) == -1)
		return (ST_OTHER);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (ST_OK);
		return (ST_KO);
	}
	if (WIFSIGNALED(status))
		return (map_signal(WTERMSIG(status)));
	return (ST_OTHER);
}
