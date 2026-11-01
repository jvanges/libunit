#include <unistd.h>

/*
** stdout_test : la fonction testee ecrit sur la sortie standard.
** Le framework bonus a redirige la sortie du fils vers /dev/null :
** ce texte est donc avale et NE polue PAS le rapport final, tandis
** que le test est quand meme execute et rapporte [OK].
*/
int	stdout_test(void)
{
	write(1, "ceci ne doit pas apparaitre dans le rapport\n", 43);
	return (0);
}
