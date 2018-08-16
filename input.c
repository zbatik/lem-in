/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:13:27 by event             #+#    #+#             */
/*   Updated: 2018/08/16 17:11:16 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_input(t_lem *lem)
{
	char buf[256];
	char *input;
	int ret;

	input = NULL;
	ret = 0;
	input = ft_strnew(0);
	while ((ret = read(0, &buf, 256) != 0))
		ft_strreplace(&input, ft_strjoin(buf, input));
	lem->raw = ft_strsplit(input, '\n');
	free(input);
}
