/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:00:55 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:00:57 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			temp = (*alst)->next;
			free(*alst);
			*alst = NULL;
			*alst = temp;
		}
	}
}
