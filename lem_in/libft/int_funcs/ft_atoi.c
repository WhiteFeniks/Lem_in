/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:58:56 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:58:58 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi(char const *str)
{
	intmax_t	num;
	char		mult;

	while (ft_iswhite(*str))
		str++;
	mult = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + mult * (*str - '0');
		str++;
	}
	return (num);
}
