/*
** sigfpe_test : division entiere par zero.
** Sur x86, l'instruction idiv leve une exception -> le noyau envoie
** SIGFPE au processus. Le volatile empeche l'evaluation a la compilation.
*/
int	sigfpe_test(void)
{
	volatile int	dividende;
	volatile int	diviseur;

	dividende = 42;
	diviseur = 0;
	return (dividende / diviseur);
}
