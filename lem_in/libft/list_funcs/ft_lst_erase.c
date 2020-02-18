/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_erase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:00:17 by umoff             #+#    #+#             */
/*   Updated: 2020/02/15 14:22:21 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Функция стирания списка
*/

t_list	*ft_lst_erase(t_list *head)
{
	t_list *temp;

	if (!head)
		return (NULL);
	while (head)
	{
		temp = head;
		head = head->next;
		if (temp->content)
		{
			free(temp->content);
			temp->content = NULL;
		}
		temp->content_size = 0;
		free(temp);
	}
	return (NULL);
}
