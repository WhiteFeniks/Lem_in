/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:43:34 by umoff             #+#    #+#             */
/*   Updated: 2020/02/17 20:51:39 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция передвижения муравьев L1-2 L1-3 и т.д.
*/

int		make_step(t_data *data)
{
	int i;
	int moved;

	i = 0;
	moved = 0;
	while (i < data->ant_qty)
	{
		if (data->ants[i].path->next &&
			(!data->room_arr[NEXT_ROOM_IN_PATH(i)].visited ||
			data->room_arr[NEXT_ROOM_IN_PATH(i)].status == 'e'))
		{
			data->room_arr[ROOM_IN_PATH(i)].visited = 0;
			data->ants[i].path = data->ants[i].path->next;
			data->room_arr[ROOM_IN_PATH(i)].visited = 1;
			moved++;
			ft_printf("L%i-%s ", data->ants[i].name,
			data->room_arr[ROOM_IN_PATH(i)].name);
		}
		i++;
	}
	ft_printf("\n");
	return (moved);
}

/*
** Функция хождения муравьев
*/

void	transfer_ants(t_data *data)
{
	int moved;

	create_ants(data);
	appoint_path(data);
	moved = EMPTY;
	while (moved)
		moved = make_step(data);
}
