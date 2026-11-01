/* ************************************************************************** */
/*                                                                            */
/*  clear_tests.c : liberation complete de la liste de tests                  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include <stdlib.h>

/*
** clear_tests : libere chaque maillon de la liste ET le nom duplique
** lors du load_test(). Appelee par launch_tests() une fois la routine
** terminee : le sujet impose zero fuite memoire.
** Le pointeur de tete passe a NULL, ce qui rend la liste reutilisable.
*/
void	clear_tests(t_unit_test **list)
{
	t_unit_test	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->name);
		free(*list);
		*list = tmp;
	}
}
