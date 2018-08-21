/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:51:58 by event             #+#    #+#             */
/*   Updated: 2018/08/21 11:36:41 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	room_num_from_name(char *name, t_graph **map);
{
	while (*map)
	{
		if (ft_strequ((*map)->name), name)
			return ((*map)->num);
		map++;
	}
	return (-1);
}

char *room_name_from_num(int num, t_graph **map)
{
	while (*map)
	{
		if (num == (*map)->num)
			return ((*map)->name);
		map++;
	}
	return ("");
}
