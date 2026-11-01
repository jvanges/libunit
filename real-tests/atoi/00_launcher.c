#include "tests_atoi.h"
#include "../../framework/includes/libunit.h"

/*
** atoi_launcher : charge les 6 tests de ft_atoi puis les execute.
** Commenter une ligne load_test() pour passer un test sous silence.
*/
int	atoi_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &atoi_basic_test);
	load_test(&testlist, "Negative test", &atoi_negative_test);
	load_test(&testlist, "Whitespace test", &atoi_whitespace_test);
	load_test(&testlist, "Trailing junk test", &atoi_trailing_junk_test);
	load_test(&testlist, "Multiple signs test", &atoi_multiple_signs_test);
	load_test(&testlist, "Zero test", &atoi_zero_test);
	return (launch_tests(&testlist, "ATOI"));
}
