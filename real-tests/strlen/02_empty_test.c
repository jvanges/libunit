#include "tests_strlen.h"

/*
** Chaine vide : le premier caractere est deja le '\0' final,
** la longueur attendue est 0. Piege classique des boucles mal bornees.
*/
int	strlen_empty_test(void)
{
	if (ft_strlen("") == 0u)
		return (0);
	return (-1);
}
