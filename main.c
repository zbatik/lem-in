/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/16 17:14:35 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int main(void)
{
	t_lem *lem;

	lem = malloc(sizeof(lem));
	get_input(lem);
	ft_putstrarr(lem->raw);
	char *room_names[] = {"1", "2", "3", "4"};
	lem->map = new_map(4, room_names);
	add_connection(lem->map, 1, 0);
	add_connection(lem->map, 0, 2);
	add_connection(lem->map, 0, 3);
	add_connection(lem->map, 2, 1);
//	print_map(room_list);
	map_del(&lem->map);
}
