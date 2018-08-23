/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:43:40 by event             #+#    #+#             */
/*   Updated: 2018/08/23 19:54:18 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	room = NULL;
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
		put_error(lem, "Error: no starting room");
	if (start->start && start->end)
		return ;
	search(start, &ind, moves);
	if (ind == 0)
		put_error(lem, "Error: no valid path");
	ind--;
	ft_putstrarr(lem->raw);
	print_walk(lem, lem->num_ants, ind, moves);
	free(moves);
}
