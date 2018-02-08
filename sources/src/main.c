#include <lem-in.h>

static void	init(t_lem *e)
{
	e->n_ants = 0;
	e->n_rooms = 0;
	e->start.ant = -1;
	e->end.ant = -1;
	e->r = (t_room*)NULL;
}

static void printdata(t_lem *e)
{
	t_room	*tmp;

	tmp = e->r;
	ft_printf("n_ants=%d   n_rooms=%d\n\n", e->n_ants, e->n_rooms);
	ft_printf("name=%s   ant=%d\npos.x=%d   pos.y=%d\nconnections=%d  names:\n"
	, e->start.name, e->start.ant, e->start.pos.x, e->start.pos.y, e->start.connect);
	for (int i = 0; i < e->start.connect; i++)
		ft_printf(" %s ", e->start.names[i]);
	ft_printf("\nsteps to end=%d   checked=%d\n", e->start.steps, e->start.checked);
	ft_printf("\n");
	while (tmp != NULL)
	{
		ft_printf("name=%s   ant=%d\npos.x=%d   pos.y=%d\nconnections=%d  names:\n"
		, tmp->name, tmp->ant, tmp->pos.x, tmp->pos.y, tmp->connect);
		for (int i = 0; i < tmp->connect; i++)
			ft_printf(" %s ", tmp->names[i]);
	ft_printf("\nsteps to end=%d   checked=%d\n", tmp->steps, tmp->checked);
		ft_printf("\n");
		tmp = tmp->next;
	}
	ft_printf("name=%s   ant=%d\npos.x=%d   pos.y=%d\nconnections=%d  names:\n"
	, e->end.name, e->end.ant, e->end.pos.x, e->end.pos.y, e->end.connect);
	for (int i = 0; i < e->end.connect; i++)
		ft_printf(" %s ", e->end.names[i]);
	ft_printf("\nsteps to end=%d   checked=%d\n", e->end.steps, e->end.checked);
	ft_printf("\n");
}

int	main()
{
	t_lem	e;

	init(&e);
	getdata(&e);
	if (e.n_ants == 0 || e.n_rooms == 0 || e.start.ant == -1 || e.end.ant == -1)
		lem_error(0);
	set_steps(&e);
	if (e.start.steps == e.n_rooms + 1)
		lem_error(0);
	printdata(&e);
	return (0);
}
