/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:09:58 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/25 15:37:43 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_bool	isroomdesc(char *line)
{
	if (ft_countc(line, ' ') == 2 && *line != '#')
		return (1);
	return (0);
}

t_bool	isconnectdesc(char *line)
{
	if (ft_countc(line, '-') == 1 && *line != '#'
			&& ft_countc(line, ' ') == 0)
		return (1);
	return (0);
}

t_bool	is_vaild(char **raw)
{
	while (*raw)
	{
		raw++;
		if (*raw == NULL)
			break ;
		if (ft_strlen(*raw) < 1)
			return (0);
		if (isconnectdesc(*raw))
			continue ;
		if (isroomdesc(*raw))
			continue ;
		if (**raw == '#')
			continue ;
		return (0);
	}
	return (1);
}
