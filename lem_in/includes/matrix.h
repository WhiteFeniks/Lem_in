/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:55:08 by umoff             #+#    #+#             */
/*   Updated: 2020/02/08 14:55:11 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include "libft.h"
# include <math.h>

typedef struct	s_matrix
{
	int			**values;
	size_t		rows;
	size_t		cols;
}				t_matrix;

t_matrix		create_matrix(size_t rows, size_t cols);
void			print_matrix(t_matrix m);
void			free_matrix(t_matrix m);
t_matrix		dup_matrix(t_matrix src);

#endif
