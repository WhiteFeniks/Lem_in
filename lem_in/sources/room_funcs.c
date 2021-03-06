/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:31:29 by umoff             #+#    #+#             */
/*   Updated: 2020/02/22 14:24:05 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Получение индекса по имени
*/

int		get_index_by_name(t_list *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strequ(((t_room *)rooms->content)->name, name))
			return (((t_room *)rooms->content)->index);
		rooms = rooms->next;
	}
	return (-1);
}

/*
** Получение индекса по статусу
*/

int		get_index_by_status(t_room *room_arr, int room_num, char status)
{
	int i;

	i = 0;
	while (i < room_num)
	{
		if (room_arr[i].status == status)
			return (room_arr[i].index);
		i++;
	}
	return (-1);
}
