#include "mandatory/tests_mandatory.h"

/*
** main de la routine de tests obligatoire.
** Appelle chaque launcher ; pour sauter une routine entiere, commenter
** la ligne correspondante (possibilite exigee par le sujet).
** La limite de 25 lignes ne s'applique pas a ce main (sujet V.2).
** Retour : 0 en cas de succes complet, -1 sinon (propage aux exit code).
*/
int	main(void)
{
	int	ret;

	ret = 0;
	if (mandatory_launcher() == -1)
		ret = -1;
	return (ret);
}
