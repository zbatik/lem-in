/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:00:33 by event             #+#    #+#             */
/*   Updated: 2018/08/17 15:49:38 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	print_room(t_graph *room)
{
	int i;

	i = 0;
	ft_putendl("______________________________");
	ft_putstr("Room No.:\t");
	ft_putnbr(room->num);
	ft_putchar('\n');
	ft_putstr("Room Name:\t");
	ft_putendl(room->name);
	i = -1;
	ft_putstr("Links to:\t");
	while (++i < room->num_links)
	{
		ft_putnbr(room->links[i]->num);
	}
	ft_putchar('\n');
}

void	print_map(t_graph **map)
{
	while (*map)
	{
		print_room(*map);
		map++;
	}
}
