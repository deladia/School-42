/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:52:48 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/08 12:43:16 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insert_matrix_3(t_map **matrix, t_map *ptr, int a)
{
	int		i;
	int		j;

	i = 1;
	while (i <= a)
	{
		j = 1;
		while (j <= a)
		{
			if (i == 1 && j == 1)
				j++;
			ptr->right = create_cell(i, j);
			ptr->right->left = ptr;
			ptr->right->up = *matrix;
			ptr = ptr->right;
			(*matrix)->down = ptr;
			if ((*matrix)->right)
				*matrix = (*matrix)->right;
			j++;
		}
		i++;
	}
}

void	insert_matrix_2(t_map **map, t_map **matrix, int a)
{
	t_map	*ptr;
	t_map	*tmp;

	find_matrix(matrix, 1, 1);
	ptr = *matrix;
	ptr->down = create_cell(1, 1);
	ptr->down->up = ptr;
	ptr = ptr->down;
	*matrix = (*matrix)->right;
	tmp = *map;
	insert_matrix_3(matrix, ptr, a);
	*matrix = ptr;
	insert_hash(&tmp, matrix, a);
}

void	insert_matrix_1(t_map **map, t_map **matrix, int a)
{
	int		i;
	int		j;
	t_map	*tmp;

	i = 1;
	tmp = *map;
	while (i <= a)
	{
		j = 1;
		while (j <= a)
		{
			if (!*matrix)
				*matrix = create_cell(i, j);
			else
			{
				(*matrix)->right = create_cell(i, j);
				(*matrix)->right->left = *matrix;
				*matrix = (*matrix)->right;
			}
			j++;
		}
		i++;
	}
	insert_hash(&tmp, matrix, a);
}
