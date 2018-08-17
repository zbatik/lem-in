/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:13:27 by event             #+#    #+#             */
/*   Updated: 2018/08/17 15:48:53 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		**get_input(void)
{
	char	buf[256];
	char	*input;
	char	**raw;
	int		ret;

	input = NULL;
	ret = 0;
	input = ft_strnew(0);
	while ((ret = read(0, &buf, 256) != 0))
		ft_strreplace(&input, ft_strjoin(buf, input));
	raw = ft_strsplit(input, '\n');
	free(input);
	return (raw);
}

static t_bool	isroomdesc(char *line)
{
	if (ft_countc(line, ' ') && *line != '#')
		return (1);
	return (0);
}

static int		count_rooms(char **raw)
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

static char		**get_room_names(char **raw, int num_rooms)
{
	char	**room_names;
	int		i;

	room_names = malloc(sizeof(char*) * (num_rooms + 1));
	i = 0;
	while (*raw != NULL)
	{
		if (isroomdesc(*raw))
			room_names[i++] = ft_strsub(*raw, 0, ft_indexcin(*raw, ' '));
		raw++;
	}
	room_names[i] = NULL;
	return (room_names);
}

t_lem			*init(void)
{
	char	**room_names;
	char	**raw;
	t_lem	*lem;

	lem = malloc(sizeof(lem));
	raw = get_input();
	lem->num_ants = ft_atoi(raw[0]);
	lem->num_rooms = count_rooms(raw + 1);
	room_names = get_room_names(raw, lem->num_rooms);
	lem->map = new_map(lem->num_rooms, room_names);
	ft_arrdel(&room_names, lem->num_rooms);
//	ft_arrdel(raw);
	return (lem);
}
