#include "strlen/tests_strlen.h"
#include "atoi/tests_atoi.h"
#include "split/tests_split.h"

/*
** main de la routine de tests reels (15 tests sur la libft).
** Appelle chaque launcher ; pour sauter une routine entiere, commenter
** la ligne correspondante (possibilite exigee par le sujet).
** Retour : 0 si tous les tests ont reussi, -1 sinon.
*/
int	main(void)
{
	int	ret;

	ret = 0;
	if (strlen_launcher() == -1)
		ret = -1;
	if (atoi_launcher() == -1)
		ret = -1;
	if (split_launcher() == -1)
		ret = -1;
	return (ret);
}
