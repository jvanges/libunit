#include "tests_strlen.h"

/*
** Les espaces comptent comme n'importe quel caractere :
** "hello world" contient 11 caracteres, espace inclus.
*/
int	strlen_spaces_test(void)
{
	if (ft_strlen("hello world") == 11u)
		return (0);
	return (-1);
}
