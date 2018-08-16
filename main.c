/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/16 14:23:07 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int main(void)
{
	t_graph **room_list;
	
	char *room_names[] = {"1", "2", "3", "4"};
	room_list = new_map(4, room_names);
	add_connection(room_list, 1, 0);
	add_connection(room_list, 0, 2);
	add_connection(room_list, 0, 3);
	add_connection(room_list, 2, 1);
	print_map(room_list);
}
