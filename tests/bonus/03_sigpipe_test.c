#include <unistd.h>

/*
** sigpipe_test : ecriture sur un tube dont l'extremite de lecture
** a ete fermee. Le noyau envoie alors SIGPIPE au processus ecrivain,
** dont la disposition par defaut termine le processus.
*/
int	sigpipe_test(void)
{
	int	fds[2];

	if (pipe(fds) == -1)
		return (-1);
	close(fds[0]);
	write(fds[1], "x", 1);
	close(fds[1]);
	return (0);
}
