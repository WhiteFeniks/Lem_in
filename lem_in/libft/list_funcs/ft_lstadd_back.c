/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:00:23 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:00:26 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list *alst, t_list *new)
{
	if (!alst && new)
		return (new);
	if (alst && new)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
		new->next = NULL;
	}
	return (new);
}
