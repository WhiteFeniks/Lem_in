/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:38:07 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:38:09 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		i = 0;
		while (i < size + 1)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
