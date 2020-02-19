/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:21:57 by umoff             #+#    #+#             */
/*   Updated: 2020/02/19 16:31:58 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Проверка на очередь
*/

int		in_queue(t_list *queue, int index)
{
	while (queue)
	{
		if (*((int *)queue->content) == index)
			return (1);
		queue = queue->next;
	}
	return (0);
}

/*
** Добавление в очередь
*/

void	add_to_queue(t_list **queue, t_data *data, int index)
{
	int			j;

	j = 0;
	while (j < data->room_num)
	{
		if (data->adj.values[index][j] == 1 && !data->room_arr[j].visit &&
			!in_queue(*queue, j))
		{
			if (!*queue)
				*queue = ft_lstnew(&j, sizeof(int));
			else
				ft_lstadd_back(*queue, ft_lstnew(&j, sizeof(int)));
		}
		j++;
	}
}
