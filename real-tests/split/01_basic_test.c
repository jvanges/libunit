#include "tests_split.h"

/*
** Decoupage nominal : "bonjour 42 monde" avec ' ' -> 3 mots + tableau
** termine par NULL. ft_strncmp avec la longueur +1 garantit l'egalite
** exacte (le '\0' est compare lui aussi).
** Toutes les chaines allouees sont liberees avant le retour.
*/
int	split_basic_test(void)
{
	char	**r;
	int		ok;
	int		i;

	r = ft_split("bonjour 42 monde", ' ');
	ok = r && r[0] && r[1] && r[2] && !r[3]
		&& !ft_strncmp(r[0], "bonjour", 8)
		&& !ft_strncmp(r[1], "42", 3)
		&& !ft_strncmp(r[2], "monde", 6);
	i = 0;
	if (r)
		while (r[i])
			free(r[i++]);
	free(r);
	if (ok)
		return (0);
	return (-1);
}
