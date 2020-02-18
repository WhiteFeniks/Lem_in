/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:10:25 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:10:27 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *dest;
	char *start;

	if (!s1)
		return (NULL);
	dest = ft_strnew(ft_strlen(s1));
	if (!dest)
		return (NULL);
	start = dest;
	while ((*dest++ = *s1++))
		;
	return (start);
}
