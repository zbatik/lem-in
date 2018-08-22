/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:13:27 by event             #+#    #+#             */
/*   Updated: 2018/08/22 16:51:56 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		**get_input(void)
{
	char	buf[4096];
	char	**raw;
	int		ret;

	ret = read(0, &buf, 4096);
	if (ret < 1)
	{
		ft_puterror("Error: bad input");
		exit(-1);
	}
	buf[ret] = 0;
	raw = ft_strsplit(buf, '\n');
	return (raw);
}

static t_bool	isroomdesc(char *line)
{
	if (ft_countc(line, ' ') == 2 && *line != '#')
		return (1);
	return (0);
}

static int		count_rooms(char **raw)
{
	int count;

	count = 0;
	while (*raw != NULL)
	{
		if (isroomdesc(*raw))
			count++;
		raw++;
	}
	return (count);
}

static char		**get_room_names(char **raw, int num_rooms)
{
	char	**room_names;
	int		i;

	room_names = malloc(sizeof(char*) * (num_rooms + 1));
	i = 0;
	while (*raw != NULL)
	{
		if (isroomdesc(*raw))
		{
			room_names[i] = ft_strsub(*raw, 0, ft_indexcin(*raw, ' '));
			if (*room_names[i] == 'L')
			{
				ft_puterror("Error: invalid room name");
				exit(-1);
			}
			i++;
		}
		raw++;
	}
	room_names[i] = NULL;
	return (room_names);
}

t_lem			*init(void)
{
	char	**room_names;
	char	**raw;
	t_lem	*lem;

	lem = malloc(sizeof(lem));
	raw = get_input();
	if (ft_isnumber(raw[0]))
		lem->num_ants = ft_atoi(raw[0]);
	else
		put_error("Error: no ants");
	lem->num_rooms = count_rooms(raw);
	room_names = get_room_names(raw, lem->num_rooms);
	lem->map = new_map(lem->num_rooms, room_names);
	ft_putendl("HERE");
	set_connections(lem->map, raw);
	ft_putendl("HERE");
	start_end(lem->map, raw, "start");
	start_end(lem->map, raw, "end");
	ft_putendl("HERE");
	ft_arrdel(&room_names, lem->num_rooms + 1);
	ft_putendl("HERE");
	ft_arrdel(&raw, ft_strarrlen(raw));
	ft_putendl("HERE");
	return (lem);
}
