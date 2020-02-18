/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:04:01 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:04:03 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char			*temp;
	unsigned char	const	*s;

	if (dst <= src)
	{
		temp = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp = (unsigned char *)dst;
		temp += len;
		s = (unsigned char	const *)src;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}
