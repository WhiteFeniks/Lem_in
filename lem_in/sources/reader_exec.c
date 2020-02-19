/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:39:52 by umoff             #+#    #+#             */
/*   Updated: 2020/02/19 13:50:34 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция записи инструкций start и end (комнатам назначается статус s и e)
*/

void	exec_instr(t_data *data, char *line)
{
	if (ft_strequ(line, "##start"))
	{
		if (line)
			ft_strdel(&line);
		get_next_line(FD, &line);
		line ? PRINT_LINE(line) : ERROR_MSG(line, "empty line");
		if (is_room(line))
			parse_room(data, line, 's');
		else
			ERROR_MSG(line, "incorrect room parameters");
	}
	else if (ft_strequ(line, "##end"))
	{
		if (line)
			ft_strdel(&line);
		get_next_line(FD, &line);
		line ? PRINT_LINE(line) : ERROR_MSG(line, "empty line");
		if (is_room(line))
			parse_room(data, line, 'e');
		else
			ERROR_MSG(line, "incorrect room parameters");
	}
	else
		ERROR_MSG(line, "incorrect instruction");
}

/*
** Функция которая парсит комнаты
*/

void	parse_room(t_data *data, char *line, char status)
{
	char			**arr;
	t_room			room;
	static int		index;

	arr = ft_strsplit(line, ' ');
	room.name = ft_strdup(arr[0]);
	room.x = ft_atoi(arr[1]);
	room.y = ft_atoi(arr[2]);
	check_uniqe_room(data, room, line);
	room.status = status;
	room.index = index;
	room.visit = 0;
	room.wave = -1;
	index++;
	if (!data->rooms)
		data->rooms = ft_lstnew(&room, sizeof(t_room));
	else
		ft_lstadd_back(data->rooms, ft_lstnew(&room, sizeof(t_room)));
	ft_strdel(&line);
	ft_clear_strarr(&arr);
}

/*
** Функция которая парсит связи между комнатами и добавляет данные в матрицу
** смежности
*/

void	parse_link(t_data *data, char *line)
{
	int		i;
	int		j;
	char	**arr;

	arr = ft_strsplit(line, '-');
	i = get_index_by_name(data->rooms, arr[0]);
	j = get_index_by_name(data->rooms, arr[1]);
	if (ft_strequ(arr[0], arr[1]))
	{
		ft_clear_strarr(&arr);
		ERROR_MSG(line, "self connected room");
	}
	if (i == -1 || j == -1)
	{
		ft_clear_strarr(&arr);
		ERROR_MSG(line, "there is no room with such name");
	}
	data->adj.values[i][j] = 1;
	data->adj.values[j][i] = 1;
	ft_strdel(&line);
	ft_clear_strarr(&arr);
}

/*
** Функция проверки валидность статуса (start и end)
*/

void	check_status(t_data *data)
{
	int		start;
	int		end;
	t_list	*rooms;

	start = 0;
	end = 0;
	rooms = data->rooms;
	while (rooms)
	{
		if (((t_room *)rooms->content)->status == 's')
			start++;
		if (((t_room *)rooms->content)->status == 'e')
			end++;
		rooms = rooms->next;
	}
	if (start == 0)
		ERROR_MSG(NULL, "START room wasn`t specified");
	if (end == 0)
		ERROR_MSG(NULL, "END room wasn`t specified");
	if (start > 1)
		ERROR_MSG(NULL, "there are more than one START room");
	if (end > 1)
		ERROR_MSG(NULL, "there are more than one END room");
}
