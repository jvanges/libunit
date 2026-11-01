/* ************************************************************************** */
/*                                                                            */
/*  launch_tests.c : orchestrateur d'une routine de tests                     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

/*
** launch_tests : parcourt la liste chargee par le launcher et execute
** chaque test dans son propre processus (via exec_test), puis affiche
** son resultat au fur et a mesure.
** La liste est ensuite entierement liberee (zero fuite memoire) et le
** bilan "X/Y tests checked" est affiche.
** Valeur de retour imposee par le sujet :
**   0  en cas de succes complet (tous les tests OK)
**  -1  des qu'au moins un test a echoue ou a crashe.
*/
int	launch_tests(t_unit_test **list, char *function_name)
{
	t_unit_test	*cur;
	int			total;
	int			success;
	int			status;

	cur = *list;
	total = 0;
	success = 0;
	while (cur)
	{
		status = exec_test(cur);
		print_result(function_name, cur->name, status);
		total++;
		if (status == ST_OK)
			success++;
		cur = cur->next;
	}
	clear_tests(list);
	print_summary(success, total);
	if (success == total)
		return (0);
	return (-1);
}
