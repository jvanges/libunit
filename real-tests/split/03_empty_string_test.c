#include "tests_split.h"

/*
** Chaine vide : le resultat attendu est un tableau contenant
** uniquement le pointeur NULL (aucun mot), jamais un crash ni un
** tableau a lui-meme NULL.
*/
int	split_empty_string_test(void)
{
	char	**r;
	int		ok;

	r = ft_split("", ' ');
	ok = r && !r[0];
	free(r);
	if (ok)
		return (0);
	return (-1);
}
