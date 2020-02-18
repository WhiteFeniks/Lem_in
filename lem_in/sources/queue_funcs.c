/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:39:37 by umoff             #+#    #+#             */
/*   Updated: 2020/02/17 20:39:21 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция добавления в очередь
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
** Функция добавления в очередь
*/

void	add_to_queue(t_list **queue, t_data *data, int index)
{
	int			j;

	j = 0;
	while (j < data->room_num)
	{
		if (data->adj.values[index][j] == 1 && !data->room_arr[j].visited &&
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
