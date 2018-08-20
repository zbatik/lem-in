/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/20 16:50:01 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int main(void)
{
	t_lem *lem;

	lem = init();
	printf("Num ants: %d, Num rooms: %d\n", lem->num_ants, lem->num_rooms);
	print_map(lem->map);
//	algo(lem);
	map_del(&lem->map);
	free(lem);
}
