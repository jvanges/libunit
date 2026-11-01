#ifndef TESTS_STRLEN_H
# define TESTS_STRLEN_H

# include "libft.h"

/*
** Serie de tests reels sur ft_strlen.
** Chaque test suit le prototype impose : int f(void), 0 = succes.
*/
int	strlen_basic_test(void);
int	strlen_empty_test(void);
int	strlen_spaces_test(void);
int	strlen_special_test(void);
int	strlen_long_test(void);

/* Launcher de la routine strlen */
int	strlen_launcher(void);

#endif
