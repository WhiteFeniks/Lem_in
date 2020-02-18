/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:38:43 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:38:45 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t		len;
	char const	*end;
	char		*str;

	if (!s)
		return (NULL);
	end = s + ft_strlen(s) - 1;
	while (ft_iswhite(*s))
		s++;
	while (ft_iswhite(*end) && end > s)
		end--;
	len = end - s + 1;
	str = ft_strnew(len);
	if (str)
	{
		while (s <= end)
			*str++ = *s++;
		return (str - len);
	}
	return (NULL);
}
