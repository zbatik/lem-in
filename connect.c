/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:11:34 by event             #+#    #+#             */
/*   Updated: 2018/08/19 17:38:35 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		name2num(char *name, t_graph **map, int len)
{
	while (*map)
	{
		if (ft_strnequ((*map)->name, name, len))
			return ((*map)->num);
		map++;
	}
	return (-1);
}

static t_bool	isconnectdesc(char *line)
{
	if (ft_countc(line, '-') == 1 && *line != '#')
	   return (1);
	return (0);
}

void			set_connections(t_graph **rooms, char **raw)
{
	int 	room1;
	int		room2;
	int		ind;

	while (*raw)
	{
		if (isconnectdesc(*raw))
		{
			ind = ft_indexcin(*raw, '-');
			room1 = name2num(*raw, rooms, ind);
			room2 = name2num(*raw + ind + 1, rooms, ft_strlen(*raw + ind));
			add_connection(rooms, room1, room2);
		}	
		raw++;
	}
}

static void		set_startend(t_graph **rooms, int room_num, char *opt)
{
	while (*rooms)
	{
		if ((*rooms)->num == room_num)
		{
			if (ft_strequ("start", opt))
				(*rooms)->start = 1;
			else if (ft_strequ("end", opt))
				(*rooms)->end = 1;
		}
		rooms++;
	}
}

void		start_end(t_graph **rooms, char **raw, char *opt)
{
	int room;

	while (*raw)
	{
		if (ft_strlen(*raw) > 2)
		{
			if (**raw == '#' && *(*raw + 1) == '#')
			{
				if (ft_strequ(*raw + 2, opt))
				{
					raw++;
					room = name2num(*raw, rooms, ft_indexcin(*raw, ' '));
					set_startend(rooms, room, opt);
					return ;
				}
			}
		}
		raw++;
	}
}
