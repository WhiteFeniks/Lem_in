/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:50:06 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/19 18:45:50 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Удаление комнаты
*/

void	delete_room(void *room, size_t content_size)
{
	if (!room)
		return ;
	ft_strdel(&(((t_room *)room)->name));
	free(room);
	content_size = 0;
}

/*
** Удаление пути
*/

void	delete_path(void *content, size_t content_size)
{
	if (!content)
		return ;
	free(content);
	content_size = 0;
}

/*
** Удаление путей
*/

void	delete_pathways(t_list **head)
{
	t_list *temp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp->content)
			ft_lst_erase((t_list *)temp->content);
		temp->content_size = 0;
		free(temp);
	}
}

/*
** Удаление массива комнат
*/

void	delete_room_arr(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->room_num)
	{
		ft_strdel(&(data->room_arr[i].name));
		i++;
	}
	free(data->room_arr);
}
