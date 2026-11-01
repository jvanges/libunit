#include "tests_strlen.h"

/*
** Chaine longue de 45 caracteres : detecte les erreurs de type int
** trop petit ou de compteur mal incremente sur les grandes entrees.
*/
int	strlen_long_test(void)
{
	const char	*str;

	str = "0123456789abcdef0123456789abcdef0123456789abc";
	if (ft_strlen(str) == 45u)
		return (0);
	return (-1);
}
