/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:59:53 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:59:56 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_len(long long n)
{
	size_t len;

	len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa_sign(long long n)
{
	long long	num;
	char		temp;
	size_t		len;
	char		*str;

	num = n;
	len = ft_get_len(n);
	str = ft_strnew(len);
	if (n == 0)
		str[0] = '0';
	len--;
	while (num)
	{
		temp = num % 10;
		temp = FT_ABS(temp);
		str[len] = temp + '0';
		num /= 10;
		len--;
	}
	if (n < 0)
		str[len] = '-';
	else
		str[len] = '+';
	return (str);
}
