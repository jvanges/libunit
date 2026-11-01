#include "tests_split.h"

/*
** Separateurs consecutifs : "a,,b,c" avec ',' -> 3 mots "a", "b", "c".
** Les sequences vides entre deux ',' ne doivent PAS produire de chaine
** vide dans le resultat : c'est LE piege classique de ft_split.
*/
int	split_multi_sep_test(void)
{
	char	**r;
	int		ok;
	int		i;

	r = ft_split("a,,b,c", ',');
	ok = r && r[0] && r[1] && r[2] && !r[3]
		&& !ft_strncmp(r[0], "a", 2)
		&& !ft_strncmp(r[1], "b", 2)
		&& !ft_strncmp(r[2], "c", 2);
	i = 0;
	if (r)
		while (r[i])
			free(r[i++]);
	free(r);
	if (ok)
		return (0);
	return (-1);
}
