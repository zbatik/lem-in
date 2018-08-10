/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:03:22 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/10 11:34:50 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct	s_lem
{
	int		num_rooms;
	t_graph	map;
}				t_lem;

typedef struct	s_graph
{
	int		ants;
	int		room_num;
	char	* room_name;
	void	**links;
}				t_graph;

#endif
