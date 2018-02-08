#include <lem-in.h>

static void		get_n_ants(char *line)
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
	++(e->n_rooms);
	return (room);
}

static void		get_command(t_lem *e, char *line)
{
	char	*nextline;

	if (ft_strstr(line, "start"))
	{
		if (e->start.ant != -1 && (e->start.ant = -1) == -1)
			return ;
		if (get_next_line(0, &nextline) <= 0)
			return ;
		e->start = get_room(e, nextline);
		e->start.ant = e->n_ants;
		//addnode(e, e->start);
	}
	else if (ft_strstr(line, "end"))
	{
		if (e->end.ant != -1 && (e->end.ant = -1) == -1)
			return ;
		if (get_next_line(0, &nextline) <= 0)
			return ;
		e->end = get_room(e, nextline);
		e->end.ant = 0;
		//addnode(e, e->end);
	}
	else
		return ;
	ft_strdel(&nextline);
}

void			getdata(t_lem *e)
{
	char	*line;
	int		line_n;

	line_n = 0;
	while (get_next_line(0, &line) > 0 && ft_printf("%s\n", line) != -1)
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
		else if (ft_countwords(line, ' ') == 3)
			addnode(e, get_room(e, line));
		else
			get_links(e, line);
		ft_strdel(&line);
	}
}
