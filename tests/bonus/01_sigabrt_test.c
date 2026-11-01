#include <stdlib.h>

/*
** sigabrt_test : abort() envoie SIGABRT au processus appelant.
** Le framework bonus doit rapporter [ABORT] (et non un simple inconnu).
*/
int	sigabrt_test(void)
{
	abort();
	return (0);
}
