/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:57:11 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:57:13 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_date(t_fq *fq)
{
	time_t		t;
	struct tm	*a;

	t = time(NULL);
	a = localtime(&t);
	if (fq->size == hh)
		return (ft_printf("%&%02d:%02d:%02d", fq->fd, a->tm_hour, a->tm_min,
				a->tm_sec));
	else if (fq->size == h)
		return (ft_printf("%&%02d:%02d", fq->fd, a->tm_hour, a->tm_min));
	else if (fq->size == l)
		return (ft_printf("%&%04d-%02d", fq->fd, a->tm_year + 1900,
				a->tm_mon + 1));
	else if (fq->size == ll)
		return (ft_printf("%&%04d-%02d-%02d", fq->fd, a->tm_year + 1900,
				a->tm_mon + 1, a->tm_mday));
	else if (fq->size == z)
		return (ft_printf("%&%04d", fq->fd, a->tm_year + 1900));
	else
		return (ft_printf("%&%04d-%02d-%02d %02d:%02d:%02d", fq->fd,
				a->tm_year + 1900, a->tm_mon + 1, a->tm_mday, a->tm_hour,
				a->tm_min, a->tm_sec));
}
