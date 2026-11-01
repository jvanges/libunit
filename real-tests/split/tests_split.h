#ifndef TESTS_SPLIT_H
# define TESTS_SPLIT_H

# include "libft.h"
# include <stdlib.h>

/*
** Serie de tests reels sur ft_split.
** Chaque chaine allouee par ft_split est liberee a la fin du test :
** politique du projet, zero fuite memoire.
*/
int	split_basic_test(void);
int	split_multi_sep_test(void);
int	split_empty_string_test(void);
int	split_only_sep_test(void);

/* Launcher de la routine split */
int	split_launcher(void);

#endif
