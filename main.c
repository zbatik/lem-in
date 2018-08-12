/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:00:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/12 16:34:05 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_data()
{
	t_dblist	*rooms;
	char		*gnl;
	char		room_name;
	int			room_num;
	
	rooms = NULL;
	room_num = 0;
	while (get_next_line(0, &gnl) != 0);
	{
		if (ft_countc(gnl, ' ') == 2)
		{
			room_name = ft_strsub(gnl, 0, ft_indexcin(gnl, ' '));
			ft_lstdbadd(&rooms, ft_lstdbnew(room_name, room_number++));
			ft_strdel(room_name);
		}
		else if (ft_countc(gnl, ' ') == 0)
		{

		}
}

int main(void)
{

}
