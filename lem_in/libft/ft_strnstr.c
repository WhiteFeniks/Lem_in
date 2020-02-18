/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:38:13 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:38:15 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	len2;

	if (!(*needle))
		return ((char *)haystack);
	len2 = ft_strlen(needle);
	while (*haystack && len >= len2)
	{
		if (*haystack == *needle &&
			!ft_memcmp(haystack, needle, len2))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
