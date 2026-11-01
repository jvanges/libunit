#include "tests_atoi.h"

/*
** Signes multiples : "--42" n'est pas un nombre valide pour atoi,
** la libc rend 0 ; ft_atoi doit se comporter a l'identique.
*/
int	atoi_multiple_signs_test(void)
{
	if (ft_atoi("--42") == atoi("--42"))
		return (0);
	return (-1);
}
