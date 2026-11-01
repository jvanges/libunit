#ifndef TESTS_ATOI_H
# define TESTS_ATOI_H

# include "libft.h"
# include <stdlib.h>

/*
** Serie de tests reels sur ft_atoi.
** Strategie : comparer le resultat de ft_atoi avec celui de la vraie
** fonction atoi() de la libc sur la meme entree : le test est impartial,
** il ne depend d'aucune valeur codee a la main.
*/
int	atoi_basic_test(void);
int	atoi_negative_test(void);
int	atoi_whitespace_test(void);
int	atoi_trailing_junk_test(void);
int	atoi_multiple_signs_test(void);
int	atoi_zero_test(void);

/* Launcher de la routine atoi */
int	atoi_launcher(void);

#endif
