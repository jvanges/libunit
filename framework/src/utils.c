/* ************************************************************************** */
/*                                                                            */
/*  utils.c : petites fonctions d'affichage autonomes                         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** lu_putstr : ecrit une chaine sur la sortie standard.
** Seul write() est autorise par le sujet : pas de printf/puts ici.
*/
void	lu_putstr(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

/*
** lu_putnbr : affiche un entier (utilise pour le bilan "X/Y tests checked").
** Recursif par dizaines pour eviter un tableau tampon.
** Seuls des entiers positifs ou nuls lui sont passes par le framework.
*/
void	lu_putnbr(int n)
{
	char	c;

	if (n >= 10)
		lu_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}
