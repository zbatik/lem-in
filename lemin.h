/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:03:22 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/16 17:07:09 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/includes/libft.h"

typedef struct	s_graph
{
	char *name;
	int	num;
	t_bool visited;
    int ant;
	int num_links;
    struct s_graph **links;// make this a list as long a the total number of rooms
}				t_graph;

typedef struct	s_lem
{
	int		num_rooms;
	t_graph	**map;
	char	**raw;

}				t_lem;

t_graph	**new_map(int num_rooms, char **room_names);
t_graph	*new_room(int room_num, int num_rooms, char *room_name);
void	add_connection(t_graph **rooms, int room1, int room2);
void	map_del(t_graph ***room);

void	get_input(t_lem *lem);

void	print_map(t_graph **map);
void	print_room(t_graph *room);


#endif
