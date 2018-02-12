/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:34:53 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/12 13:28:19 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	init(t_lem *e)
{
	e->n_ants = 0;
	e->n_rooms = 0;
	e->start.ant = -1;
	e->end.ant = -1;
	e->r = (t_room*)NULL;
}

static void	lem_memdel(t_lem *e)
{
	t_room	*tmp;

	while (e->r != NULL)
	{
		ft_strdel(&e->r->name);
		free_2d(&e->r->names);
		tmp = e->r->next;
		free(e->r);
		e->r = tmp;
	}
}

static int	check_links(t_lem *e)
{
	t_room	*tmp;

	tmp = findnode(e, e->start.name, 0);
	if (tmp == NULL || tmp->connect == 0)
		return (1);
	tmp = findnode(e, e->end.name, 0);
	if (tmp == NULL || tmp->connect == 0)
		return (1);
	return (0);
}

int			main(void)
{
	t_lem	e;

	init(&e);
	getdata(&e);
	if (e.n_ants == 0 || e.n_rooms == 0 || e.start.ant == -1 || e.end.ant == -1
		|| check_links(&e))
		lem_error(0);
	set_steps(&e);
	if (e.start.steps == e.n_rooms + 1)
		lem_error(0);
	move_ants(&e);
	lem_memdel(&e);
	return (0);
}
