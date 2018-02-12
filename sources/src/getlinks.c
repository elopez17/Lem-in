/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlinks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:38:26 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/12 11:44:13 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#define FINDLIST(e, s1, s2)({findlist(e,s1,s2);ft_strdel(&s1);ft_strdel(&s2);})

static void	init_links(t_lem *e)
{
	t_room	*tmp;

	tmp = e->r;
	while (tmp != NULL)
	{
		tmp->steps = e->n_rooms + 1;
		tmp->checked = 0;
		tmp->names = (char**)ft_memalloc(sizeof(char*) * (e->n_rooms + 1));
		tmp = tmp->next;
	}
}

static void	findlist(t_lem *e, char *s1, char *s2)
{
	t_room	*tmp1;
	t_room	*tmp2;

	tmp1 = e->r;
	tmp2 = e->r;
	while (tmp1 != NULL)
	{
		if (ft_strequ(tmp1->name, s1))
			break ;
		tmp1 = tmp1->next;
	}
	while (tmp2 != NULL)
	{
		if (ft_strequ(tmp2->name, s2))
			break ;
		tmp2 = tmp2->next;
	}
	(tmp1 == NULL || tmp2 == NULL) ? lem_error(0) : 0;
	tmp1->names[tmp1->connect] = ft_strdup(tmp2->name);
	tmp2->names[tmp2->connect] = ft_strdup(tmp1->name);
	++(tmp1->connect);
	++(tmp2->connect);
}

static int	is_comment(char **str)
{
	if ((*str)[0] == '#' && (*str)[1] != '#')
	{
		ft_strdel(str);
		return (1);
	}
	return (0);
}

void		get_links(t_lem *e, char *line)
{
	char	*s;
	char	*s1;
	char	*s2;

	init_links(e);
	if (ft_countwords(line, ' ') != 1 || ft_countwords(line, '-') != 2)
		lem_error(0);
	s1 = ft_strcsub(line, '-');
	s2 = ft_strcsub(ft_strchr(line, '-') + 1, '\0');
	(s1 == NULL || s2 == NULL || ft_strequ(s1, s2)) ? lem_error(0) : 0;
	FINDLIST(e, s1, s2);
	while (get_next_line(0, &s) > 0 && ft_printf("%s\n", s) != -10)
	{
		if (is_comment(&s))
			continue ;
		if (ft_countwords(s, ' ') != 1 || ft_countwords(s, '-') != 2)
			lem_error(0);
		s1 = ft_strcsub(s, '-');
		s2 = ft_strcsub(ft_strchr(s, '-') + 1, '\0');
		(s1 == NULL || s2 == NULL || ft_strequ(s1, s2)) ? lem_error(0) : 0;
		FINDLIST(e, s1, s2);
		ft_strdel(&s);
	}
}
