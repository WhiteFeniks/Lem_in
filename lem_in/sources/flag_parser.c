/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:30:43 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/19 16:30:26 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Обнуление флагов
*/

static void	init_flags(t_flags *flags)
{
	flags->e = 0;
	flags->p = 0;
	flags->s = 0;
	flags->h = 0;
}

/*
** Описание флагов:
** -е - показать ошибки,
** -p - показать возможные пути,
** -s - удалить вывод данных файла,
** -h - показать помощь,
*/

static void	detect_flag(char *arg, t_flags *flags)
{
	if (ft_strequ(arg, "-e"))
		flags->e = 1;
	else if (ft_strequ(arg, "-p"))
		flags->p = 1;
	else if (ft_strequ(arg, "-s"))
		flags->s = 1;
	else if (ft_strequ(arg, "-h"))
		flags->h = 1;
	else
		flags->e ? error(ft_strdup(arg), "incorrect flag")
					: error(NULL, NULL);
}

/*
** Парсер флагов
*/

t_flags		parse_flags(char ***args, int argc)
{
	t_flags	flags;

	init_flags(&flags);
	while (argc)
	{
		if (**args && ***args == '-' && !ft_is_number(**args))
			detect_flag(**args, &flags);
		(*args)++;
		argc--;
	}
	return (flags);
}
