/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:00:06 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:00:08 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_len(long long n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(long long n)
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
	return (str);
}
