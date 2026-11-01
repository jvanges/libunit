#include "tests_mandatory.h"
#include "../../framework/includes/libunit.h"

/*
** mandatory_launcher : charge puis execute les 4 tests obligatoires.
**
** Pour passer un test sous silence, il suffit de commenter la ligne
** load_test() correspondante (possibilite exigee par la mini-norme).
** La limite de 25 lignes ne s'applique pas aux launchers (sujet V.2).
*/
int	mandatory_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "OK test", &ok_test);
	load_test(&testlist, "KO test", &ko_test);
	load_test(&testlist, "SIGSEGV test", &sigsegv_test);
	load_test(&testlist, "SIGBUS test", &sigbus_test);
	return (launch_tests(&testlist, "DUMMY"));
}
