/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:57:23 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:57:25 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sign_float(t_fq *fq)
{
	if (fq->fn < 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '-');
	if (fq->flags[PLUS] == '1' && fq->fn >= 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '+');
}

void	compute_width_float(t_fq *fq)
{
	if (fq->flags[MINUS] == '1')
	{
		add_sign_float(fq);
		fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
	}
	else if (fq->flags[MINUS] == '0')
	{
		add_sign_float(fq);
		fq->s = fill_right(fq->s, fq->width, &(fq->l),
				fq->flags[ZERO] == 1 ? '0' : ' ');
	}
}

void	form_f(t_fq *fq, va_list ap)
{
	if (fq->size == L)
		fq->fn = va_arg(ap, long double);
	else
		fq->fn = va_arg(ap, double);
	fq->s = ft_ftoa_abs(fq->fn, fq->precision == -1 ? 6 : fq->precision);
	fq->l = ft_strlen(fq->s);
	if (fq->width > fq->l)
		compute_width_float(fq);
	else
	{
		add_sign_float(fq);
		compute_space(fq);
	}
	if (fq->flags[HOOK] == '1')
		*(ft_strchr(fq->s, '.')) = ',';
}
