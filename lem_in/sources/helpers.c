/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:39:17 by umoff             #+#    #+#             */
/*   Updated: 2020/02/18 13:36:08 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Функция распечатки ошибок
*/

void	error(char *line, char *desc)
{
	if (!line && !desc)
		exit(write(1, "Error\n", 6));
	else if (!line && desc)
		exit(ft_printf("Error: %s\n", desc));
	else
	{
		ft_printf("Error: %s <%s>\n", desc, line);
		ft_strdel(&line);
		exit(1);
	}
}

/*
** Функция распечатка путей
*/

void	print_pathways(t_data data)
{
	t_list *temp;
	t_list *pathways;

	ft_printf("\nNumber of possible pathways: %u\n",
				ft_lstlen(data.pathways));
	pathways = data.pathways;
	while (pathways)
	{
		temp = (t_list *)(pathways->content);
		ft_printf("\n");
		while (temp)
		{
			if (!temp->next)
				ft_printf("[%s]",
					data.room_arr[*((int *)temp->content)].name);
			else
				ft_printf("[%s]->",
					data.room_arr[*((int *)temp->content)].name);
			temp = temp->next;
		}
		ft_printf(" - steps : %u", pathways->content_size);
		ft_printf("\n");
		pathways = pathways->next;
	}
	ft_printf("\n");
}

/*
** Функция распечатки справки
*/

void	print_help(void)
{
	ft_printf("Usage: ./lem-in [flags] < map_file\n\n");
	ft_printf("Flags description:\n");
	ft_printf("-e - explain errors\n");
	ft_printf("-p - show possible pathways\n");
	ft_printf("-s - supress output of file data\n");
	ft_printf("-h - show help\n");
	exit(1);
}
