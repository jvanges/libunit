#include "mandatory/tests_mandatory.h"
#include "bonus/tests_bonus.h"

/*
** main du binaire bonus : enchaine la routine obligatoire puis la routine
** qui valide chaque fonctionnalite bonus. Le journal BONUS.log est produit
** dans le repertoire courant par launch_tests_bonus().
*/
int	main(void)
{
	int	ret;

	ret = 0;
	if (mandatory_launcher() == -1)
		ret = -1;
	if (bonus_launcher() == -1)
		ret = -1;
	return (ret);
}
