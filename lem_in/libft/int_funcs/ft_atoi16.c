/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:59:02 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:59:04 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi16(char const *str)
{
	long long int	ans;
	int				str_base;
	char			symb;
	char			sign;

	ans = 0;
	str_base = 16;
	sign = *str == '-' ? -1 : 1;
	if (sign == -1)
		str++;
	if (str[0] == '0' && str[1] == 'x')
		str += 2;
	while ((symb = ft_tolower(*str)))
	{
		ans *= str_base;
		ans += sign * (symb < '9' ? symb - '0' : symb - 'a' + 10);
		str++;
	}
	return (ans);
}
