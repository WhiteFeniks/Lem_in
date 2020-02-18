/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:43:29 by umoff             #+#    #+#             */
/*   Updated: 2020/02/17 20:54:26 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция получиения индекса по имени
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
** Функция получения индекса по статусу
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

/*
** Функция установки посящения
*/

void	set_visited(t_list *rooms, int index)
{
	while (rooms)
	{
		if (((t_room *)rooms->content)->index == index)
			((t_room *)rooms->content)->visited = 1;
		rooms = rooms->next;
	}
}
