/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:39:13 by umoff             #+#    #+#             */
/*   Updated: 2020/02/15 14:15:26 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция удалении комнаты
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
** Функция удаляния пути
*/

void	delete_path(void *content, size_t content_size)
{
	if (!content)
		return ;
	free(content);
	content_size = 0;
}

/*
** Функция удаления пути
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
** Функция удаления массива комнат
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
