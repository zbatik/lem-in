/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:43:40 by event             #+#    #+#             */
/*   Updated: 2018/08/21 11:59:40 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		*num2name(int num, t_graph **map)
{
	while (*map)
	{
		if (num == (*map)->num)
			return ((*map)->name);
		map++;
	}
	return ("");
}

static t_graph	*select_start(t_graph **rooms)
{
	while (*rooms)
	{
		if ((*rooms)->start)
			return (*rooms);
		rooms++;
	}
	return (NULL);
}

static int		update_search(t_graph *room, int *ind, int *moves)
{
	moves[*ind] = room->num;
	*ind += 1;
	return (1);
}

static int		search(t_graph *start, int *ind, int *moves)
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
			return (update_search(room, ind, moves));
		if (search(room, ind, moves))
			return (update_search(room, ind, moves));
	}
	return (0);
}

void			algo(t_lem *lem)
{
	t_graph	*start;
	int		*moves;
	int		ind;

	ind = 0;
	moves = malloc(sizeof(int) * lem->num_rooms);
	start = select_start(lem->map);
	if (start == NULL)
	{
		ft_puterror("Error: no starting room");
		exit(-1);
	}
	search(start, &ind, moves);
	moves[ind] = start->num;
	while (ind >= 0)
	{
		ft_putstr(num2name(moves[ind--], lem->map));
		ft_putstr("->");
	}
	ft_putendl("");
}
