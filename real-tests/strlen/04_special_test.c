#include "tests_strlen.h"

/*
** Caracteres d'echappement : '\n', '\t' et '!' forment 3 caracteres.
** Verifie que ft_strlen ne confond pas les sequences speciales
** avec le terminateur '\0'.
*/
int	strlen_special_test(void)
{
	if (ft_strlen("\n\t!") == 3u)
		return (0);
	return (-1);
}
