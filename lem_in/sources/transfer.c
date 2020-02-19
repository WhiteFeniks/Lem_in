/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:43:34 by umoff             #+#    #+#             */
/*   Updated: 2020/02/19 13:44:43 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция передвижения муравьев L1-2 L1-3 и т.д.
** *((int *)data->ants[i].path->content) -> комната в пути
** *((int *)data->ants[i].path->next->content) -> следующая комната в пути
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
			(!data->room_arr[*((int *)data->ants[i].path->next->content)].visit
			||
			data->room_arr[*((int *)data->ants[i].path->next->content)].status
			== 'e'))
		{
			data->room_arr[*((int *)data->ants[i].path->content)].visit = 0;
			data->ants[i].path = data->ants[i].path->next;
			data->room_arr[*((int *)data->ants[i].path->content)].visit = 1;
			moved++;
			ft_printf("L%i-%s ", data->ants[i].name,
			data->room_arr[*((int *)data->ants[i].path->content)].name);
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
