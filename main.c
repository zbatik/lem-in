/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/23 20:01:11 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	clean(t_lem **lem)
{
	t_lem *l;

	l = *lem;
	if (l->map != NULL)
	{
		map_del(&l->map, l->num_rooms);
		free(l->map);
		l->map = NULL;
	}
	if (l->raw != NULL)
		ft_arrdel(&l->raw, ft_strarrlen(l->raw));
	free(l);
	l = NULL;
}

int	main(void)
{
	t_lem *lem;

	lem = init();
	algo(lem);
	clean(&lem);
}
