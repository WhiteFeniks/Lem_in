/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:45:11 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/19 18:45:50 by klaurine         ###   ########.fr       */
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
		ERROR_MSG(line, "non-positive value");
	if (data->ant_qty > 100000)
		ERROR_MSG(line, "Too much ants. [limit 100 000]");
	ft_strdel(&line);
}

/*
** Ппроверка файла, если нет муравьев и файл пустой
*/

void	check_file(t_data *data, char *line, int i)
{
	if (i && !data->ant_qty)
		ERROR_MSG(line, "no ants quantity");
	if (!i)
		ERROR_MSG(line, "file is empty");
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
			ERROR_MSG(line, "the room with such name is already exists");
		if (room.x == (((t_room *)temp->content)->x) &&
			room.y == (((t_room *)temp->content)->y))
			ERROR_MSG(line,
						"the room with the same coordinates is already exists");
		temp = temp->next;
	}
}
