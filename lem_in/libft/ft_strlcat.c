/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:10:49 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:10:52 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;
	size_t temp;

	temp = dstsize;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > ft_strlen(dst))
	{
		dstsize -= 1;
		while (*dst && dstsize--)
			dst++;
		while (dstsize-- && (*dst++ = *src++))
			;
		*dst = '\0';
	}
	dstsize = temp;
	return ((dstsize < dst_len) ? dstsize + src_len : dst_len + src_len);
}
