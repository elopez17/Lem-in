#include <lem-in.h>

static void	init(t_lem *e)
{
	e->n_ants = 0;
	e->n_rooms = 0;
	e->start.ant = -1;
	e->end.ant = -1;
	e->r = (t_room*)NULL;
}

int	main()
{
	t_lem	e;

	init(&e);
	getdata(&e);
	if (e.n_ants == 0 || e.n_rooms == 0 || e.start.ant == -1 || e.end.ant == -1)
		lem_error(0);
	return (0);
}
