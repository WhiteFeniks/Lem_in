/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:43:22 by umoff             #+#    #+#             */
/*   Updated: 2020/02/17 18:23:22 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция считывания количества муравьей
*/

static void	read_ant_qty(t_data *data, char **line)
{
	while (get_next_line(FD, line) > 0)
	{
		if (!(*line))
			ERROR_MSG(*line, "empty line");
		PRINT_LINE(*line);
		if (is_comment(*line))
		{
			ft_strdel(line);
			continue ;
		}
		if (ft_is_number(*line) && *line)
		{
			write_ants_qty(data, *line);
			return ;
		}
		ERROR_MSG(*line, "incorrect ants quantity value");
	}
	ERROR_MSG(*line, "empty file");
}

/*
** Функция считывания комнат
*/

static void	read_rooms(t_data *data, char **line)
{
	while (get_next_line(FD, line) > 0)
	{
		if (!(*line))
			ERROR_MSG(*line, "empty line");
		PRINT_LINE(*line);
		if (is_comment(*line))
		{
			ft_strdel(line);
			continue ;
		}
		else if (is_instruct(*line))
			exec_instr(data, *line);
		else if (is_room(*line))
			parse_room(data, *line, 'c');
		else if (is_link(*line))
			return ;
		else
			ERROR_MSG(*line, "incorrect room parameters");
	}
}

/*
** Функция построения матрицы смежности
*/

static void	build_adj_matrix(t_data *data, char **line)
{
	size_t	room_qty;

	room_qty = ft_lstlen(data->rooms);
	data->adj = create_matrix(room_qty, room_qty);
	parse_link(data, *line);
	while (get_next_line(FD, line) > 0)
	{
		if (!(*line) && ft_printf("Warning: empty line\n"))
			return ;
		PRINT_LINE(*line);
		if (is_comment(*line))
		{
			ft_strdel(line);
			continue ;
		}
		if (is_link(*line))
			parse_link(data, *line);
		else
		{
			ft_printf("Warning: incorrect link <%s>\n", *line);
			return ;
		}
	}
}

/*
** Функция записи комнат в массив
*/

static void	write_rooms_to_arr(t_data *data)
{
	int		index;
	t_list	*temp;
	size_t	len;

	len = ft_lstlen(data->rooms);
	data->room_num = len;
	data->room_arr = (t_room *)malloc(sizeof(t_room) * len);
	temp = data->rooms;
	while (temp)
	{
		index = ((t_room *)temp->content)->index;
		ft_memcpy(&(data->room_arr[index]), (t_room *)temp->content,
					sizeof(t_room));
		data->room_arr[index].name = ft_strdup(((t_room *)temp->content)->name);
		temp = temp->next;
	}
}

/*
** Функция считывания данных
*/

void		read_data(t_data *data)
{
	char	*line;

	line = NULL;
	read_ant_qty(data, &line);
	read_rooms(data, &line);
	if (!ft_lstlen(data->rooms))
		ERROR_MSG(NULL, "rooms weren`t specified");
	if (!line)
		ERROR_MSG(line, "there are no links between rooms");
	check_status(data);
	build_adj_matrix(data, &line);
	ft_printf("\n");
	write_rooms_to_arr(data);
}
