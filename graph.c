/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:47:03 by event             #+#    #+#             */
/*   Updated: 2018/08/15 16:27:36 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
 
typedef struct	s_graph;
{
	char *name;
	int	num;
    int ant;
	int num_links;
    struct s_graph **links;// make this a list as long a the total number of rooms
}				t_graph;
 
t_graph	*new_room(int room_num, char *room_name)
{
	t_graph *room;

	room = malloc(sizeof(t_graph));
	room->name = room_name;
	room->num = room_num;
    room->ant = 0;
    room->links = NULL;
    return (room);
}

void	add_connection(t_graph *ant_house, int room1, room2);
 

