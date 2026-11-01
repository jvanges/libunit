#include "tests_strlen.h"

/*
** Cas nominal : une chaine ordinaire de 5 caracteres.
** Le suffixe u evite tout avertissement de comparaison signee/non signee
** (ft_strlen retourne un size_t).
*/
int	strlen_basic_test(void)
{
	if (ft_strlen("hello") == 5u)
		return (0);
	return (-1);
}
