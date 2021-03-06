/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:17:08 by umoff             #+#    #+#             */
/*   Updated: 2020/02/19 16:29:41 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Создание муравьев (нумерация муравьев)
*/

void	create_ants(t_data *data)
{
	int i;

	data->ants = (t_ant *)malloc(sizeof(t_ant) * data->ant_qty);
	i = 0;
	while (i < data->ant_qty)
	{
		data->ants[i].name = i + 1;
		i++;
	}
}

/*
** Получение кратчайшего пути
*/

t_list	*get_shortest_path(t_data *data)
{
	t_list	*temp;
	t_list	*short_path;

	temp = data->pathways;
	short_path = data->pathways;
	while (temp)
	{
		if (short_path->content_size > temp->content_size)
			short_path = temp;
		temp = temp->next;
	}
	short_path->content_size++;
	return ((t_list *)short_path->content);
}

/*
** Назначение пути
*/

void	appoint_path(t_data *data)
{
	int i;

	i = 0;
	while (i < data->ant_qty)
	{
		data->ants[i].path = get_shortest_path(data);
		i++;
	}
}
