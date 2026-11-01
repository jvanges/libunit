/*
** timeout_test : boucle infinie volontaire.
** Grace au bonus timeout, le fils s'est programme une alarm() :
** au bout de TEST_TIMEOUT secondes il meurt par SIGALRM et le pere
** rapporte [TIMEOUT], puis enchaine avec les tests suivants.
** Sans cette protection, toute la routine resterait bloquee ici.
*/
int	timeout_test(void)
{
	while (1)
		;
	return (0);
}
