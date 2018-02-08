/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/08 14:40:31 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <mlx.h>
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define KEYESC 53
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_visualizer
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		len;
	int		fd;
}				t_vis;

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_room
{
	char			*name;
	int				ant;
	t_coord			pos;
	int				connect;
	char			**names;
	int				steps;
	int				checked;
	struct s_room	*next; 
}				t_room;

typedef struct	s_lem
{
	int		n_ants;
	int		n_rooms;
	t_room	start;
	t_room	end;
	t_room	*r;
}				t_lem;

void	getdata(t_lem *e);
void	get_links(t_lem *e, char *line);
void	set_steps(t_lem *e);
void	addnode(t_lem *e, t_room new);
t_room	*findnode(t_lem *e, char *name, int level);
void	lem_error(int code);

#endif
