/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:55:42 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:55:45 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btreedelone(t_btree **abtree, void (*del)(void *, size_t))
{
	if (abtree && *abtree && del)
	{
		(*del)((*abtree)->content, (*abtree)->content_size);
		free(*abtree);
		*abtree = NULL;
	}
}
