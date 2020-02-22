/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:02:40 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/22 14:10:32 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Создание матрицы (двумерный массиив)
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
