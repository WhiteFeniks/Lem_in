/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:39:23 by umoff             #+#    #+#             */
/*   Updated: 2020/02/18 13:36:32 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция очистки данных
*/

void		clear_data(t_data *data)
{
	free_matrix(data->adj);
	ft_lstdel(&(data->rooms), &delete_room);
	delete_room_arr(data);
	delete_pathways(&(data->pathways));
	free(data->ants);
}

/*
** Функция обнуления количества муравьев, комнат, массивов комнат, путей
*/

static void	init_data(t_data *data)
{
	data->ant_qty = 0;
	data->rooms = NULL;
	data->room_arr = NULL;
	data->pathways = NULL;
}

/*
** Главная функция
*/

int			main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (argc > 1)
		data.flags = parse_flags(&argv, argc);
	if (data.flags.h)
		print_help();
	read_data(&data);
	wave_front(&data);
	detect_pathways(&data);
	if (data.flags.p)
		print_pathways(data);
	transfer_ants(&data);
	clear_data(&data);
	return (0);
}
