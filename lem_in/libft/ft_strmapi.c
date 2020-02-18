/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:37:18 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:37:21 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		i = 0;
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
