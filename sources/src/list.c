/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:39:20 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/08 20:39:27 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

t_room	*findnode(t_lem *e, char *name, int level)
{
	t_room	*tmp;

	tmp = e->r;
	while (tmp != NULL)
	{
		if (level != 0 && tmp->steps == level && tmp->checked == 0)
			return (tmp);
		else if (level == 0 && ft_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	addnode(t_lem *e, t_room new)
{
	t_room	*tmp;

	tmp = (t_room*)malloc(sizeof(t_room));
	*tmp = new;
	tmp->next = e->r;
	e->r = tmp;
}
