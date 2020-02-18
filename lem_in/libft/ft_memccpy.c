/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:03:33 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:03:35 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	while (n)
	{
		if ((*((unsigned char *)dst++) = *((unsigned char *)src++)) ==
			(unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
