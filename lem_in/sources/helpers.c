/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:06:24 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/19 17:01:05 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Распечатка ошибок
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
** Распечатка путей
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
** Распечатка справки
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

/*
** Проверка на существование линии и печать ошибки
*/

void	check_line(t_data *data, char *line)
{
	if (line)
		data->flags.s == 1 ? 0 : ft_printf("%s\n", line);
	else
		data->flags.e ? error(line, "empty line") : error(NULL, NULL);
}
