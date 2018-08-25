/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:47:03 by event             #+#    #+#             */
/*   Updated: 2018/08/25 15:36:55 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_graph	*new_room(int room_num, int num_rooms, char *room_name)
{
	t_graph	*room;
	int		i;

	room = malloc(sizeof(t_graph));
	room->name = room_name;
	room->num = room_num;
	room->visited = 0;
	room->start = 0;
	room->end = 0;
	room->links = malloc(sizeof(&room) * (num_rooms + 1));
	i = -1;
	while (++i <= num_rooms + 1)
		room->links[i] = NULL;
	return (room);
}

t_graph			**new_map(int num_rooms, char **room_names)
{
	t_graph	**room_list;
	int		i;

	room_list = malloc(sizeof(room_list) * (num_rooms + 1));
	i = -1;
	while (++i < num_rooms)
		room_list[i] = new_room(i, num_rooms, ft_strdup(room_names[i]));
	room_list[i] = NULL;
	return (room_list);
}

static void		set_connection(t_graph **rooms, t_graph *room, int conn_room)
{
	int i;

	i = -1;
	while (room->links[++i])
	{
		if (room->links[i]->num == conn_room)
			return ;
	}
	room->links[room->num_links] = rooms[conn_room];
	room->num_links += 1;
}

void			add_connection(t_graph **rooms, int room1, int room2)
{
	t_graph *room;
	int		i;

	i = -1;
	room = NULL;
	while (rooms[++i])
	{
		room = rooms[i];
		if (room->num == room1)
			set_connection(rooms, room, room2);
		if (room->num == room2)
			set_connection(rooms, room, room1);
	}
}

void			map_del(t_graph ***room_list, int num_rooms)
{
	int		i;
	t_graph	*room;

	i = -1;
	while (++i < num_rooms)
	{
		room = (*room_list)[i];
		ft_strdel(&room->name);
		free(room->links);
		free(room);
		room = NULL;
	}
	free(*room_list);
	*room_list = NULL;
}
