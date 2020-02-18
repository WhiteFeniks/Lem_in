/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_strarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:05:00 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:05:02 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_strarr(char ***str_arr)
{
	size_t	i;
	char	**tmp;

	if (!(*str_arr))
		return ;
	tmp = *str_arr;
	i = 0;
	while (tmp[i])
	{
		ft_strclr(tmp[i]);
		ft_strdel(&tmp[i]);
		i++;
	}
	free(*str_arr);
	*str_arr = NULL;
}
