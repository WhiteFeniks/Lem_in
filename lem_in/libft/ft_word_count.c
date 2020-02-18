/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:38:48 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:38:49 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *s, char c)
{
	int		trig;
	size_t	word_count;

	trig = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != c && !trig)
		{
			word_count++;
			trig = 1;
		}
		if (*s == c && trig)
			trig = 0;
		s++;
	}
	return (word_count);
}
