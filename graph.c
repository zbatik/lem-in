/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:47:03 by event             #+#    #+#             */
/*   Updated: 2018/08/16 14:23:17 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
 
t_graph	*new_room(int room_num, int num_rooms, char *room_name)
{
	t_graph *room;

	room = malloc(sizeof(t_graph));
	room->name = room_name;
	room->num = room_num;
	room->visited = 0;
    room->ant = 0;
	room->links = malloc(sizeof(&room) * (num_rooms + 1));
    room->links[0] = NULL;
    return (room);
}

t_graph	**new_map(int num_rooms, char **room_names)
{
	t_graph	**room_list;
	int		i;

	room_list = malloc(sizeof(room_list) * (num_rooms + 1));
	i = -1;
	while (++i < num_rooms)
	{
		room_list[i] = new_room(i, num_rooms, ft_strdup(room_names[i]));
	}
	room_list[i] = NULL;
	return (room_list);
}

void	add_connection(t_graph **rooms, int room1, int room2)
{
	t_graph *room;
	int		i;

	i = -1;
	while (rooms[++i])
	{
		room = rooms[i];
		if (room->num == room1)
		{
			room->links[room->num_links] = rooms[room2];
			room->links[room->num_links + 1] = NULL;
			room->num_links += 1;
		}
		if (room->num == room2)
		{
			room->links[room->num_links] = rooms[room1];
			room->links[room->num_links + 1] = NULL;
			room->num_links += 1;
		}
	}
}


