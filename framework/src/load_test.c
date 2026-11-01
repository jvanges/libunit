/* ************************************************************************** */
/*                                                                            */
/*  load_test.c : chargement d'un test dans la liste de la routine            */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include <stdlib.h>

/*
** lu_dupstr : duplication d'une chaine, equivalent minimal de strdup().
** Recodee ici pour que la bibliotheque libunit.a reste autonome :
** elle ne depend que des fonctions autorisees par le sujet (malloc, free,
** exit, fork, wait, write) et peut donc etre reutilisee dans n'importe
** quel projet, meme sans copie de la libft.
*/
static char	*lu_dupstr(const char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
** load_test : alloue un nouveau maillon et l'ajoute en FIN de liste.
** L'ajout en fin garantit que les tests s'executent dans le meme ordre
** que leur chargement dans le launcher (00_xxx.c), comme le montre
** l'exemple du sujet.
*/
void	load_test(t_unit_test **list, char *name, int (*func)(void))
{
	t_unit_test	*new_node;
	t_unit_test	*cur;

	new_node = malloc(sizeof(t_unit_test));
	if (!new_node)
		return ;
	new_node->name = lu_dupstr(name);
	new_node->func = func;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		cur = *list;
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
	}
}
