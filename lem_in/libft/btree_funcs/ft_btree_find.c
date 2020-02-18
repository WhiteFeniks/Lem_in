/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:55:22 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:55:25 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	cmp function should returns:
**		positive number if cont1 > cont2;
**		0  - cont1 == cont2;
**		negative number if cont1 < cont2;
*/

#include "ft_btree.h"

int	ft_btree_find(t_btree *root, void *key,
				int (*cmp)(void *cont1, void *cont2))
{
	while (root)
	{
		if (cmp(key, root->content) == 0)
			return (1);
		else if (cmp(key, root->content) > 0)
			root = root->right;
		else
			root = root->left;
	}
	return (0);
}
