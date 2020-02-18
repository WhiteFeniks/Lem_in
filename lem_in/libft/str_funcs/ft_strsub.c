/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:38:39 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:38:41 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*sub;

	if (!s1)
		return (NULL);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	i = 0;
	j = start;
	while (j < start + len)
	{
		sub[i] = s1[j];
		i++;
		j++;
	}
	return (sub);
}
