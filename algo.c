/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:43:40 by event             #+#    #+#             */
/*   Updated: 2018/08/20 16:00:58 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph	*select_start(t_graph **rooms)
{
	while (*rooms)
	{
		if ((*rooms)->start)
			return (*rooms);
		rooms++;
	}
	return (NULL);
}

int	search(t_graph *start)
{
	int		i;
	t_graph *room;

	i = -1;
	while (++i < start->num_links)
	{
		room = start->links[i];
		if (room->visited)
			continue ;
		else
			room->visited = 1;
		if (room->end)
		{
			ft_putendl(room->name);
			return (room->num);;
		}
		search(room);
		ft_putendl(room->name);
	}
	return (0);
}

void	algo(t_lem *lem)
{
	t_graph	*start;

	start = select_start(lem->map);
	if (start == NULL)
	{
		ft_puterror("Error: no starting room");
		exit(-1);
	}
	search(start);
	ft_putendl(start->name);
}
