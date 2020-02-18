/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:55:16 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:55:19 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_erase(t_btree **root, void (*del)(void *, size_t))
{
	int a;

	if (!(*root))
		return ;
	a = *((int *)(*root)->content);
	ft_btree_erase(&((*root)->left), del);
	ft_btree_erase(&((*root)->right), del);
	if (!(*root)->right && !(*root)->left)
	{
		del((*root)->content, (*root)->content_size);
		free(*root);
		*root = NULL;
		return ;
	}
}
