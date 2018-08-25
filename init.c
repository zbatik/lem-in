/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:13:27 by event             #+#    #+#             */
/*   Updated: 2018/08/25 15:37:06 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#define MAX_MAP_SIZE 4096

static void		get_input(t_lem *lem)
{
	char	buf[MAX_MAP_SIZE];
	int		ret;

	ret = read(0, &buf, MAX_MAP_SIZE);
	if (ret < 1)
		put_error(lem, "Error: bad input");
	if (ret == MAX_MAP_SIZE)
		put_error(lem, "Error: map too large - limit 4kb");
	buf[ret] = 0;
	lem->raw = ft_strsplit(buf, '\n');
	if (!is_vaild(lem->raw))
		put_error(lem, "Error: invalid map");
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

static char		**get_room_names(t_lem *lem, char **raw, int num_rooms)
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
				put_error(lem, "Error: invalid room name");
			i++;
		}
		raw++;
	}
	room_names[i] = NULL;
	return (room_names);
}

static t_lem	*init_struct(void)
{
	t_lem	*lem;

	lem = malloc(sizeof(lem));
	lem->num_ants = 0;
	lem->num_rooms = 0;
	lem->raw = NULL;
	lem->map = NULL;
	return (lem);
}

t_lem			*init(void)
{
	char	**room_names;
	t_lem	*lem;

	lem = init_struct();
	get_input(lem);
	if (ft_isnumber(lem->raw[0]))
		lem->num_ants = ft_atoi(lem->raw[0]);
	else
		put_error(lem, "Error: no ants");
	if (lem->num_ants < 1)
		put_error(lem, "Error: invaild number of ants");
	lem->num_rooms = count_rooms(lem->raw);
	room_names = get_room_names(lem, lem->raw, lem->num_rooms);
	lem->map = new_map(lem->num_rooms, room_names);
	if (!set_connections(lem->map, lem->raw))
		put_error(lem, "Error unknown room");
	if (!start_end(lem->map, lem->raw, "start"))
		put_error(lem, "Error no start");
	if (!start_end(lem->map, lem->raw, "end"))
		put_error(lem, "Error no end");
	ft_arrdel(&room_names, lem->num_rooms + 1);
	return (lem);
}
