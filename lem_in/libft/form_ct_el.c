/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_ct_el.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:57:05 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:57:08 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	form_c(t_fq *fq, va_list ap)
{
	fq->s = ft_strnew(1);
	fq->l = 1;
	fq->s[0] = (unsigned char)va_arg(ap, int);
	if (fq->width > 1)
	{
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}

void	form_elips(t_fq *fq)
{
	char	c;

	fq->s = ft_strnew(1);
	fq->s[0] = '%';
	fq->l = 1;
	if (fq->width > 1)
	{
		c = fq->flags[ZERO] == '1' ? '0' : ' ';
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l), c);
	}
}

void	form_issue_out(t_fq *fq, char c)
{
	fq->type = 't';
	fq->s = ft_strnew(1);
	fq->l = 1;
	fq->s[0] = c;
	if (fq->width > 1)
	{
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}
