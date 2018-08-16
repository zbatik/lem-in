/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/16 19:37:59 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_bool	isroomdesc(char *line)
{
	if (ft_countc(*raw, ' ') && **raw != '#')
		return (1);
	return (0);
}

int		count_rooms(char **raw)
{
	int count;

	count = 0;
	while (*raw != NULL)
	{
		if (isroomdesc(*raw))
			count++;
		raw++;
	}
	return (count);
}

int		get_room_names(t_lem *lem)
{
	malloc(sizeof(char
	while (*raw != NULL)
	{
		if (isroomdesc(*raw))
			
		raw++;
	}
	return (count);


void	get_data(t_lem *lem)
{
	lem->num_ants = ft_atoi(lem->raw[0]);
	lem->num_rooms = count_rooms(lem->raw + 1);
}

int main(void)
{
	t_lem *lem;

	lem = malloc(sizeof(lem));
	get_input(lem);
	get_data(lem);
	printf("Num ants: %d, Num rooms: %d", lem->num_ants, lem->num_rooms);
	ft_putstrarr(lem->raw);
	char *room_names[] = {"1", "2", "3", "4"};
	lem->map = new_map(lem->num_rooms, room_names);
	add_connection(lem->map, 1, 0);
	add_connection(lem->map, 0, 2);
	add_connection(lem->map, 0, 3);
	add_connection(lem->map, 2, 1);
//	print_map(room_list);
	map_del(&lem->map);
}
