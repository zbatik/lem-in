/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:03:22 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/12 16:34:09 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_lem
{
	int		num_rooms;
	int		**map;
	char	**raw;

}				t_lem;

typedef struct	s_graph
{
	int		ants;
	int		room_num;
	char	* room_name;
	void	**links;
}				t_graph;

#endif
