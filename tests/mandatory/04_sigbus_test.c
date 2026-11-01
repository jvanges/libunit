#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

/*
** sigbus_test : provoque une VERITABLE erreur de bus.
** On mappe en memoire (mmap) un fichier vide, puis on lit un octet
** situe au-dela de la fin du fichier : le noyau leve SIGBUS.
** Les appels open/mmap/munmap/close n'interviennent que dans le test,
** les restrictions du sujet ne concernent que le framework lui-meme.
*/
int	sigbus_test(void)
{
	int				fd;
	char			*map;
	volatile char	c;

	fd = open("/tmp/libunit_sigbus.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	map = mmap(NULL, 1, PROT_READ, MAP_SHARED, fd, 0);
	if (map == MAP_FAILED)
	{
		close(fd);
		return (-1);
	}
	c = map[0];
	(void)c;
	munmap(map, 1);
	close(fd);
	return (0);
}
