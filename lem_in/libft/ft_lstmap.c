/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:01:15 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:01:17 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tail;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (NULL);
	new = (*f)(new);
	head = new;
	tail = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (!new)
			return (ft_lst_erase(head));
		new = (*f)(new);
		ft_lstadd_back(tail, new);
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
