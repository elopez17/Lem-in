/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:35:01 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/08 20:36:38 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

static void		del_ants(t_ants **ant, int n_ants)
{
	int	i;

	i = -1;
	while (++i < n_ants)
		ft_strdel(&(*ant)[i].room);
	ft_memdel((void**)ant);
}

static t_ants	*init_ants(t_lem *e)
{
	t_ants	*ant;
	int		i;

	ant = (t_ants*)malloc(sizeof(t_ants) * e->n_ants);
	i = -1;
	while (++i < e->n_ants)
		ant[i].room = ft_strdup(e->start.name);
	return (ant);
}

static int		findroom(t_lem *e, t_ants *ant, int i)
{
	t_room	*tmp;
	t_room	*room;
	t_room	*hold;
	int		j;

	hold = findnode(e, ant[i].room, 0);
	tmp = findnode(e, ant[i].room, 0);
	j = -1;
	while (++j < tmp->connect)
	{
		room = findnode(e, tmp->names[j], 0);
		if (room->ant && !ft_strequ(room->name, e->end.name))
			continue ;
		if (room->steps < hold->steps)
			hold = findnode(e, tmp->names[j], 0);
	}
	if (ft_strequ(hold->name, ant[i].room))
		return (0);
	tmp->ant = 0;
	ft_strdel(&(ant[i].room));
	ft_printf("L%d-%s ", i + 1, (ant[i].room = ft_strdup(hold->name)));
	if (ft_strequ(ant[i].room, e->end.name))
		return (1);
	hold->ant = 1;
	return (0);
}

void			move_ants(t_lem *e)
{
	t_room	*end;
	t_ants	*ant;
	int		i;

	ant = init_ants(e);
	end = findnode(e, e->end.name, 0);
	while (end->ant != e->n_ants)
	{
		i = -1;
		while (++i < e->n_ants)
		{
			if (ant[i].room == end->name)
				continue ;
			end->ant += findroom(e, ant, i);
		}
		ft_printf("\n");
	}
	del_ants(&ant, e->n_ants);
}
