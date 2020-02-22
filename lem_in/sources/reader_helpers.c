/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:45:11 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/22 14:29:54 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Запись в структуру положительных < 100 000 муравьев
*/

void	write_ants_qty(t_data *data, char *line)
{
	data->ant_qty = ft_atoi(line);
	if (data->ant_qty <= 0)
		data->flags.e ? error(line, "non-positive value") : error(NULL, NULL);
	if (data->ant_qty > 100000)
		data->flags.e ? error(line, "Too much ants. [limit 100 000]") :
			error(NULL, NULL);
	ft_strdel(&line);
}

/*
** Проверка уникальности комнаты. Комната с таким названием
** уже существует. Комната с такими же координатами уже существует
*/

void	check_uniqe_room(t_data *data, t_room room, char *line)
{
	t_list *temp;

	temp = data->rooms;
	while (temp)
	{
		if (ft_strequ(room.name, ((t_room *)temp->content)->name))
			data->flags.e ? error(line,
					"the room with such name is already exists") :
				error(NULL, NULL);
		if (room.x == (((t_room *)temp->content)->x) &&
			room.y == (((t_room *)temp->content)->y))
			data->flags.e ? error(line,
					"the room with the same coordinates is already exists") :
				error(NULL, NULL);
		temp = temp->next;
	}
}
