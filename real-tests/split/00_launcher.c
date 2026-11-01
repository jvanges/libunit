#include "tests_split.h"
#include "../../framework/includes/libunit.h"

/*
** split_launcher : charge les 4 tests de ft_split puis les execute.
** Commenter une ligne load_test() pour passer un test sous silence.
*/
int	split_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &split_basic_test);
	load_test(&testlist, "Multi sep test", &split_multi_sep_test);
	load_test(&testlist, "Empty string test", &split_empty_string_test);
	load_test(&testlist, "Only separators test", &split_only_sep_test);
	return (launch_tests(&testlist, "SPLIT"));
}
