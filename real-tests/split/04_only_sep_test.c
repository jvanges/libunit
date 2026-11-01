#include "tests_split.h"

/*
** Chaine reduite a des separateurs : aucun mot a extraire,
** le tableau doit la aussi ne contenir que NULL.
*/
int	split_only_sep_test(void)
{
	char	**r;
	int		ok;

	r = ft_split(",,,,,", ',');
	ok = r && !r[0];
	free(r);
	if (ok)
		return (0);
	return (-1);
}
