#include "tests_atoi.h"

/*
** Cas nominal : "42" doit donner 42.
** Impartialite : on compare avec la vraie atoi() de la libc.
*/
int	atoi_basic_test(void)
{
	if (ft_atoi("42") == atoi("42"))
		return (0);
	return (-1);
}
