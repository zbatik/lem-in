/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:00:33 by event             #+#    #+#             */
/*   Updated: 2018/08/25 14:03:03 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

static void	print_links(t_graph *room)
{
	int i;

	i = -1;
	ft_putstr("Links to:\t");
	while (++i < room->num_links)
	{
		ft_putnbr(room->links[i]->num);
		if (i != room->num_links - 1)
			ft_putstr(", ");
	}
}

void		print_room(t_graph *room)
{
	ft_putendl("______________________________");
	if (room->start)
		ft_putendl("*Starting Room");
	else if (room->end)
		ft_putendl("*End Room");
	ft_putstr("Room No.:\t");
	ft_putnbr(room->num);
	ft_putchar('\n');
	ft_putstr("Room Name:\t");
	ft_putendl(room->name);
	ft_putstr("Num links:\t");
	ft_putnbr(room->num_links);
	ft_putchar('\n');
	print_links(room);
	ft_putchar('\n');
}

void		print_map(t_graph **map)
{
	while (*map)
	{
		print_room(*map);
		map++;
	}
}

void		print_input(t_lem *lem)
{
	ft_putnbr(lem->num_ants);
	ft_putchar('\n');
	ft_putstrarr(lem->raw + 1);
	ft_putchar('\n');
}

void		put_error(t_lem *lem, char *error)
{
	ft_puterror(error);
	clean(&lem);
	exit(-1);
}
