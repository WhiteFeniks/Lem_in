/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:27:59 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/19 18:45:50 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Запись инструкций start и end (комнатам назначается статус s и e)
*/
//# define ERROR_MSG(line, s) data->flags.e ? error(line,s) : error(NULL, NULL)
//# define PRINT_LINE(line) data->flags.s == 1 ? 0 : ft_printf("%s\n", line)
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
            data->flags.e ? error(line, "incorrect room parameters") :
            error(NULL, NULL);
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
            data->flags.e ? error("incorrect room parameters") :
            error(NULL, NULL);
	}
	else
        data->flags.e ? error(line, "incorrect instruction") :
        error(NULL, NULL);
}

/*
** Парсер комнаты
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
** Парсер связи между комнатами и добавление данных в матрицу смежности
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
        data->flags.e ? error(line, "self connected room") : error(NULL, NULL);
}
	if (i == -1 || j == -1)
	{
		ft_clear_strarr(&arr);
        data->flags.e ? error(line, "there is no room with such name") :
        error(NULL, NULL);
	}
	data->adj.values[i][j] = 1;
	data->adj.values[j][i] = 1;
	ft_strdel(&line);
	ft_clear_strarr(&arr);
}

/*
** Проверка на валидность статуса (start и end)
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
	if (start == 0 && data->flags.e)
        error(NULL, "START room wasn`t specified");
	if (end == 0 && data->flags.e)
        error(NULL, "END room wasn`t specified");
	if (start > 1 && data->flags.e)
        error(NULL, "there are more than one START room");
	if (end > 1 && data->flags.e)
       error(NULL, "there are more than one END room");
	if ((start == 0 || end == 0 || start > 1 || end > 1) && !(data->flags.e))
	    error(NULL, NULL);
}
