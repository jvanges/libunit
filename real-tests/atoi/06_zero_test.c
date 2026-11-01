#include "tests_atoi.h"

/*
** "0" doit donner 0 (et pas un comportement indefini) ;
** cas limite souvent oublie des implementations manuelles.
*/
int	atoi_zero_test(void)
{
	if (ft_atoi("0") == atoi("0") && ft_atoi("0") == 0)
		return (0);
	return (-1);
}
