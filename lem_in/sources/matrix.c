/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:02:40 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/19 18:45:50 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Создание матрицы (двумерный массив)
*/

t_matrix	create_matrix(size_t rows, size_t cols)
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	m.rows = rows;
	m.cols = cols;
	m.values = (int **)malloc(sizeof(int *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		m.values[i] = (int *)malloc(sizeof(int) * cols);
		j = 0;
		while (j < cols)
		{
			m.values[i][j] = 0;
			j++;
		}
		i++;
	}
	m.values[i] = NULL;
	return (m);
}

/*
** Очищение матрицы (двумерный массив)
*/

void		free_matrix(t_matrix m)
{
	size_t i;

	i = 0;
	while (i < m.rows)
	{
		free(m.values[i]);
		m.values[i] = NULL;
		i++;
	}
	free(m.values);
	m.values = NULL;
}

/*
** Дублирование матрицы
*/

t_matrix	dup_matrix(t_matrix src)
{
	t_matrix	dest;
	size_t		i;
	size_t		j;

	dest.rows = src.rows;
	dest.cols = src.cols;
	dest = create_matrix(dest.rows, dest.cols);
	i = 0;
	while (i < dest.rows)
	{
		j = 0;
		while (j < dest.cols)
		{
			dest.values[i][j] = src.values[i][j];
			j++;
		}
		i++;
	}
	return (dest);
}

/*
** Печать матрицы
*/

void		print_matrix(t_matrix m)
{
	size_t i;
	size_t j;

	if (!(m.values))
	{
		ft_putendl("The matrix doesn`t exist");
		return ;
	}
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			ft_printf("%i ", m.values[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
