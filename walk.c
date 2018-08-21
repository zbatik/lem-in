/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:08:30 by event             #+#    #+#             */
/*   Updated: 2018/08/21 13:15:40 by event            ###   ########.fr       */
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

void			print_walk(t_lem *lem, int num_ants, int ind, int *moves)
{
	int i;
	int j;

	i = -1;
	while (++i < num_ants)
	{
		j = -1;
		while (++j <= ind)
		{
			ft_putchar('L');
			ft_putnbr(i + 1);
			ft_putchar('-');
			ft_putstr(num2name(moves[ind - j], lem->map));
			ft_putchar('\n');
		}
	}
}
