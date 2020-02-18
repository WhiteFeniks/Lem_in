/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:57:46 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:57:50 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	form_s(t_fq *fq, va_list ap)
{
	char	*t;

	fq->s = ft_strdup(va_arg(ap, char *));
	if (!fq->s)
		fq->s = ft_strdup("(null)");
	fq->l = ft_strlen(fq->s);
	if (fq->precision >= 0 && fq->precision < (int)fq->l)
	{
		t = fq->s;
		fq->s = ft_strsub(fq->s, 0, fq->precision);
		fq->l = fq->precision;
		ft_strdel(&t);
	}
	if (fq->width > fq->l)
	{
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}
