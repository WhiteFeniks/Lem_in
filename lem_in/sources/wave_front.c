/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:24:27 by umoff             #+#    #+#             */
/*   Updated: 2020/02/19 13:44:10 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Пометить волну
*/

void	mark_wave(t_data data, t_list *queue, int wave)
{
	while (queue)
	{
		if (data.room_arr[*((int *)queue->content)].wave == -1)
			data.room_arr[*((int *)queue->content)].wave = wave;
		queue = queue->next;
	}
}

/*
** Обрабатываем начальную вершину
*/

void	handle_start_vertex(t_data *data, t_list **queue)
{
	int	index;

	index = get_index_by_status(data->room_arr, data->room_num, 's');
	data->room_arr[index].wave = 0;
	data->room_arr[index].visit = 1;
	add_to_queue(queue, data, index);
	mark_wave(*data, *queue, 1);
}

/*
** Обнуление посещений
*/

void	unset_visit(t_data *data)
{
	int i;

	i = 0;
	while (i < data->room_num)
	{
		data->room_arr[i].visit = 0;
		i++;
	}
}

/*
** Нумерация по фронтам волны (поиск в ширину)
*/

void	wave_front(t_data *data)
{
	t_list	*queue;
	int		index;
	int		wave;

	queue = NULL;
	handle_start_vertex(data, &queue);
	wave = 1;
	while (queue)
	{
		index = *((int *)queue->content);
		if (data->room_arr[index].wave > wave)
			wave++;
		if (!data->room_arr[index].visit)
		{
			add_to_queue(&queue, data, index);
			mark_wave(*data, queue, wave + 1);
			data->room_arr[index].visit = 1;
			ft_lstdel_front(&queue);
		}
	}
	unset_visit(data);
}
