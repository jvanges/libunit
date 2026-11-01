/*
** sigill_test : __builtin_trap() demande au compilateur d'emettre une
** instruction machine illegale (ud2 sur x86) -> SIGILL a l'execution.
** C'est un builtin cc/gcc, aucun appel systeme supplementaire n'est requis.
*/
int	sigill_test(void)
{
	__builtin_trap();
	return (0);
}
