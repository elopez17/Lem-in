#include <lem-in.h>

static void	set_members(t_lem *e, t_room *tmp)
{
	t_room	*tmp2;
	int		i;

	i = -1;
	while (++i < tmp->connect)
	{
		tmp2 = findnode(e, tmp->names[i], 0);
		if (tmp->steps + 1 < tmp2->steps)
			tmp2->steps = tmp->steps + 1;
	}
	tmp->checked = 1;
}

void	set_steps(t_lem *e)
{
	t_room	*tmp;
	int		level;

	tmp = findnode(e, e->end.name, 0);
	tmp->steps = 0;
	set_members(e, tmp);// this func will set all of its members to next level.
	//so far E's members(level1) have been set. next is to find those level1s
	// and set their members
	level = 0;
	while (++level <= e->n_rooms)
	{
		while ((tmp = findnode(e, "\0", level)) != NULL)
			set_members(e, tmp);
	}
	tmp = findnode(e, e->start.name, 0);
	e->start = *tmp;
	tmp = findnode(e, e->end.name, 0);
	e->end = *tmp;
}
