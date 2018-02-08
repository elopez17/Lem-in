#include <lem-in.h>

void	addnode(t_lem *e, t_room new)
{
	t_room	*tmp;

	tmp = (t_room*)malloc(sizeof(t_room));
	*tmp = new;
	tmp->next = e->r;
	e->r = tmp;
}
