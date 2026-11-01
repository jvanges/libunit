#include <stddef.h>

/*
** sigsegv_test : provoque une VERITABLE faute de segmentation en ecrivant
** a l'adresse NULL (page non mappee -> le noyau envoie SIGSEGV au fils).
** Le pointeur est volatile pour empecher le compilateur de supprimer
** l'acces memoire lors de l'optimisation.
*/
int	sigsegv_test(void)
{
	volatile char	*p;

	p = NULL;
	*p = 'x';
	return (0);
}
