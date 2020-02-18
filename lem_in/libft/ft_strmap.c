/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:10:59 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:11:01 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
