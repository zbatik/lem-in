/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:03:22 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/21 12:05:33 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct	s_graph
{
	char			*name;
	int				num;
	int				num_links;
	t_bool			start;
	t_bool			end;
	t_bool			visited;
	struct s_graph	**links;
}				t_graph;

typedef struct	s_lem
{
	int		num_ants;
	int		num_rooms;
	t_graph	**map;

}				t_lem;

t_graph			**new_map(int num_rooms, char **room_names);
void			add_connection(t_graph **rooms, int room1, int room2);
void			map_del(t_graph ***room);

t_lem			*init(void);
void			set_connections(t_graph **rooms, char **raw);
void			start_end(t_graph **rooms, char **raw, char *opt);

void			algo(t_lem *lem);

void			print_map(t_graph **map);
void			print_room(t_graph *room);
void			put_error(char *error);

#endif
