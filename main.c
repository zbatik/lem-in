/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/17 15:39:29 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int main(void)
{
	t_lem *lem;

	lem = init();
	printf("Num ants: %d, Num rooms: %d", lem->num_ants, lem->num_rooms);
	add_connection(lem->map, 1, 0);
	add_connection(lem->map, 0, 2);
	add_connection(lem->map, 0, 3);
	add_connection(lem->map, 2, 1);
	print_map(lem->map);
	map_del(&lem->map);
}
