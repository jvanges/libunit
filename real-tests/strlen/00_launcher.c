#include "tests_strlen.h"
#include "../../framework/includes/libunit.h"

/*
** strlen_launcher : charge les 5 tests de ft_strlen puis les execute.
** Commenter une ligne load_test() pour passer un test sous silence.
*/
int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &strlen_basic_test);
	load_test(&testlist, "Empty string test", &strlen_empty_test);
	load_test(&testlist, "Spaces test", &strlen_spaces_test);
	load_test(&testlist, "Special chars test", &strlen_special_test);
	load_test(&testlist, "Long string test", &strlen_long_test);
	return (launch_tests(&testlist, "STRLEN"));
}
