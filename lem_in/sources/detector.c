/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:39:03 by umoff             #+#    #+#             */
/*   Updated: 2020/02/17 19:23:14 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция получения следующих вершин и подсчета шагов
*/

int		get_next_vertex(t_data data, int index)
{
	int steps;
	int vertex;
	int j;

	steps = INT_MAX;
	vertex = EMPTY;
	j = 0;
	while (j < data.room_num)
	{
		if (data.adj.values[index][j] &&
			!data.room_arr[j].visited &&
			data.room_arr[j].wave < steps)
		{
			steps = data.room_arr[j].wave;
			vertex = j;
		}
		j++;
	}
	return (vertex);
}

/*
** Функция нахождения пути (списка)
*/

void	find_path_to_start(t_data *data, t_list **path, int index)
{
	int vertex;

	if (data->room_arr[index].status == 's')
		return ;
	data->room_arr[index].visited = 1;
	vertex = get_next_vertex(*data, index);
	if (vertex == EMPTY)
	{
		ft_lstdel(path, &delete_path);
		return ;
	}
	ft_lstadd(path, ft_lstnew(&vertex, sizeof(vertex)));
	find_path_to_start(data, path, vertex);
}

/*
** Функция получения количества путей
*/

int		get_qty_ways(t_data data, int index)
{
	int ways;
	int j;

	ways = 0;
	j = 0;
	while (j < data.room_num)
	{
		if (data.adj.values[index][j])
			ways++;
		j++;
	}
	return (ways);
}

/*
** Функция добавления путя к другим путям
*/

void	add_to_pathways(t_data *data, t_list *path)
{
	t_list *temp;

	if (!(data->pathways))
	{
		data->pathways = ft_lstnew(NULL, 0);
		data->pathways->content = path;
		data->pathways->content_size = ft_lstlen(path) - 1;
	}
	else
	{
		temp = ft_lstnew(NULL, 0);
		temp->content = path;
		temp->content_size = ft_lstlen(path) - 1;
		ft_lstadd_back(data->pathways, temp);
	}
}

/*
** Функция нахождения путей
*/

void	detect_pathways(t_data *data)
{
	int		index;
	int		possible_ways;
	t_list	*path;

	index = get_index_by_status(data->room_arr, data->room_num, 'e');
	possible_ways = get_qty_ways(*data, index);
	if (!possible_ways)
		ERROR_MSG(NULL, "the END room isn`n connected with any other room");
	while (possible_ways)
	{
		path = ft_lstnew(&index, sizeof(index));
		find_path_to_start(data, &path, index);
		possible_ways--;
		if (!path)
			continue ;
		else
			add_to_pathways(data, path);
	}
	if (!ft_lstlen(data->pathways))
		ERROR_MSG(NULL, "there are no possible ways");
	unset_visited(data);
}
