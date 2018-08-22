/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/22 16:48:43 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(void)
{
	t_lem *lem;

	lem = init();
	algo(lem);
	map_del(&lem->map, lem->num_rooms);
	free(lem->map);
	lem->map = NULL;
	free(lem);
	lem = NULL;
}
