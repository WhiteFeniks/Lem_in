/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:03:27 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:03:30 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*temp;

	if (size == 0)
		return (NULL);
	temp = (char *)malloc(size);
	if (temp)
	{
		i = 0;
		while (i < size)
		{
			temp[i] = 0;
			i++;
		}
		return ((void *)temp);
	}
	return (NULL);
}
