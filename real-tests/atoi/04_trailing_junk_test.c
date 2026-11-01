#include "tests_atoi.h"

/*
** La lecture doit s'arreter au premier caractere non numerique :
** "42abc" vaut 42, le reste est ignore.
*/
int	atoi_trailing_junk_test(void)
{
	if (ft_atoi("42abc") == atoi("42abc"))
		return (0);
	return (-1);
}
