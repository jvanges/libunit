#include "tests_bonus.h"
#include "../../framework/includes/libunit_bonus.h"

/*
** bonus_launcher : execute les tests des fonctionnalites bonus via
** launch_tests_bonus() : couleurs ANSI, timeout, detection etendue
** des signaux, capture de stdout et journal BONUS.log.
** Commenter une ligne load_test() pour passer un test sous silence.
*/
int	bonus_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "SIGABRT test", &sigabrt_test);
	load_test(&testlist, "SIGFPE test", &sigfpe_test);
	load_test(&testlist, "SIGPIPE test", &sigpipe_test);
	load_test(&testlist, "SIGILL test", &sigill_test);
	load_test(&testlist, "TIMEOUT test", &timeout_test);
	load_test(&testlist, "STDOUT capture test", &stdout_test);
	return (launch_tests_bonus(&testlist, "BONUS"));
}
