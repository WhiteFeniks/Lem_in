/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_inorder_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:55:28 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:55:31 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_inorder_print(t_btree *root, void (*p)(void *))
{
	if (!root)
		return ;
	ft_btree_inorder_print(root->left, p);
	p(root->content);
	ft_btree_inorder_print(root->right, p);
}
