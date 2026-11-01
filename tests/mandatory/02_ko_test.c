/*
** ko_test : un test qui echoue volontairement.
** Retourner -1 fait exit(-1) dans le fils ; le code ressort tronque
** a 8 bits (255) mais reste != 0, donc le pere le rapporte [KO].
*/
int	ko_test(void)
{
	return (-1);
}
