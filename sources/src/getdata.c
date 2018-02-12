/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:37:10 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/12 13:08:20 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		get_n_ants(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0' && line[i] != '-')
	{
		if (line[i] >= '0' && line[i] <= '9')
			return (ft_atoi(line + i));
	}
	return (0);
}

static t_room	get_room(t_lem *e, char *line)
{
	int		i;
	t_room	room;

	i = -1;
	room.ant = 0;
	if (ft_countwords(line, ' ') != 3)
		lem_error(0);
	while (line[++i] != '\0' && line[i] == ' ')
		;
	if ((room.name = ft_strcsub(line + i, ' ')) == NULL)
		lem_error(0);
	i += ft_strlen(room.name);
	if (line[i] == '\0' || ft_strlen(room.name) == 0)
		lem_error(0);
	room.pos.x = ft_atoi(line + i);
	room.pos.y = ft_atoi(ft_strrchr(line, ' '));
	room.next = NULL;
	room.connect = 0;
	++(e->n_rooms);
	return (room);
}

static int		clr_command(char *line)
{
	if (ft_strstr(line, "blue"))
		ft_printf("%{BL}");
	else if (ft_strstr(line, "cyan"))
		ft_printf("%{TQ}");
	else if (ft_strstr(line, "red"))
		ft_printf("%{RD}");
	else if (ft_strstr(line, "purple"))
		ft_printf("%{PU}");
	else if (ft_strstr(line, "green"))
		ft_printf("%{GR}");
	else if (ft_strstr(line, "yellow"))
		ft_printf("%{YL}");
	return (1);
}

static void		get_command(t_lem *e, char *line)
{
	char	*nxline;

	if (ft_strstr(line, "start"))
	{
		if (e->start.ant != -1 && (e->start.ant = -1) == -1)
			return ;
		if (get_next_line(0, &nxline) <= 0 || ft_printf("%s\n", nxline) == -10)
			return ;
		e->start = get_room(e, nxline);
		e->start.ant = e->n_ants;
		addnode(e, e->start);
	}
	else if (ft_strstr(line, "end"))
	{
		if (e->end.ant != -1 && (e->end.ant = -1) == -1)
			return ;
		if (get_next_line(0, &nxline) <= 0 || ft_printf("%s\n", nxline) == -10)
			return ;
		addnode(e, (e->end = get_room(e, nxline)));
	}
	else if (clr_command(line))
		return ;
	ft_strdel(&nxline);
}

void			getdata(t_lem *e)
{
	char	*line;
	int		line_n;

	line_n = 0;
	while (get_next_line(0, &line) > 0 && ft_printf("%s\n", line) != -10)
	{
		if (line[0] == '#' && line[1] != '#')
		{
			ft_strdel(&line);
			continue ;
		}
		if (++line_n == 1)
			e->n_ants = get_n_ants(line);
		else if (line[0] == '#' && line[1] == '#')
			get_command(e, line);
		else if (ft_countwords(line, ' ') == 3 && line[0] != 'L')
			addnode(e, get_room(e, line));
		else
			get_links(e, line);
		ft_strdel(&line);
	}
}
