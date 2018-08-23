/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:11:34 by event             #+#    #+#             */
/*   Updated: 2018/08/23 19:57:07 by zack             ###   ########.fr       */
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
	if (ft_countc(line, '-') == 1 && *line != '#'
			&& ft_countc(line, ' ') == 0)
		return (1);
	return (0);
}

int			set_connections(t_graph **rooms, char **raw)
{
	int room1;
	int room2;
	int ind;

	room1 = -1;
	room2 = -1;
	ind = -1;
	while (*raw)
	{
		if (isconnectdesc(*raw))
		{
			ind = ft_indexcin(*raw, '-');
			room1 = name2num(*raw, rooms, ind);
			room2 = name2num(*raw + ind + 1, rooms, ft_strlen(*raw + ind));
			if (room1 == -1 || room2 == -1)
				return (0);
			add_connection(rooms, room1, room2);
		}
		raw++;
	}
	return (1);
}

static void		set_startend(t_graph **rooms, int room_num, char *opt)
{
	while (*rooms)
	{
		if ((*rooms)->num == room_num)
		{
			if (ft_strequ("start", opt))
			{
				(*rooms)->start = 1;
				(*rooms)->visited = 1;
			}
			else if (ft_strequ("end", opt))
				(*rooms)->end = 1;
		}
		rooms++;
	}
}

int			start_end(t_graph **rooms, char **raw, char *opt)
{
	int room;

	room = -1;
	while (*raw)
	{
		if (ft_strlen(*raw) > 2)
		{
			if (**raw == '#' && *(*raw + 1) == '#')
			{
				if (ft_strequ(*raw + 2, opt))
				{
					while (**(++raw) == '#')
						raw++;
					room = name2num(*raw, rooms, ft_indexcin(*raw, ' '));
					set_startend(rooms, room, opt);
					return (1);
				}
			}
		}
		raw++;
	}
	return (0);
}
