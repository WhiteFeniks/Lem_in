/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:00:49 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:00:52 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_front(t_list **alst)
{
	t_list *temp;

	if (alst && *alst)
	{
		temp = (*alst)->next;
		if ((*alst)->content)
		{
			free((*alst)->content);
			(*alst)->content = NULL;
		}
		(*alst)->content_size = 0;
		free(*alst);
		*alst = temp;
	}
}
