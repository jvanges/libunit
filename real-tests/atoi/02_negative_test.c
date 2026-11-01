#include "tests_atoi.h"

/*
** Signe moins : "-42" doit donner -42.
*/
int	atoi_negative_test(void)
{
	if (ft_atoi("-42") == atoi("-42"))
		return (0);
	return (-1);
}
