#include "tests_atoi.h"

/*
** Blancs initiaux : espaces, tabulations et retours a la ligne doivent
** etre sautes avant la lecture du signe et des chiffres.
*/
int	atoi_whitespace_test(void)
{
	if (ft_atoi("  \t\n 42") == atoi("  \t\n 42"))
		return (0);
	return (-1);
}
