/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:10:11 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 15:10:14 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char const *s1, char const *s2)
{
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
