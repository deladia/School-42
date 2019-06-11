/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:47:10 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/07 19:03:52 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		delete_row_2(t_map **matrix, t_list_matrix **stack)
{
	find_matrix(matrix, 1, 1);
	push(stack, matrix);
	while (*matrix)
	{
		if ((*matrix)->up)
		{
			(*matrix)->up->down = (*matrix)->down;
			if ((*matrix)->down)
				(*matrix)->down->up = (*matrix)->up;
		}
		else if ((*matrix)->down)
			(*matrix)->down->up = NULL;
		else
			*matrix = NULL;
		if (!(*matrix) || !(*matrix)->right)
			break ;
		*matrix = (*matrix)->right;
	}
	return (1);
}

int		delete_letters(t_map **matrix, t_list_matrix **stack, char c)
{
	int i;

	i = 0;
	while ((*matrix)->up)
		*matrix = (*matrix)->up;
	while (*matrix)
	{
		find_matrix(matrix, 1, 1);
		while (*matrix)
		{
			if ((*matrix)->letter == c)
			{
				i += delete_row_2(matrix, stack);
				break ;
			}
			if (!(*matrix)->right ||
			(ft_isalpha((*matrix)->letter) && (*matrix)->letter != c))
				break ;
			*matrix = (*matrix)->right;
		}
		if (!*matrix || !(*matrix)->down)
			break ;
		*matrix = (*matrix)->down;
	}
	return (i);
}

int		find_letter_in_col(t_map **matrix, char symb,
		t_map *tmp, t_list_matrix **stack)
{
	int x;
	int y;
	int i;

	x = tmp->x;
	y = tmp->y;
	i = 0;
	while ((*matrix)->up)
		*matrix = (*matrix)->up;
	while (*matrix)
	{
		if (ft_isalpha((*matrix)->letter) && (*matrix)->letter != symb)
		{
			find_matrix(matrix, x, y);
			i += delete_row_2(matrix, stack);
		}
		find_matrix(matrix, x, y);
		if (!(*matrix)->down)
			break ;
		*matrix = (*matrix)->down;
	}
	return (i);
}

void	find_row(t_map **matrix, int nbr)
{
	find_matrix(matrix, 1, 1);
	while ((*matrix)->up)
		*matrix = (*matrix)->up;
	nbr--;
	while (nbr--)
	{
		if (!(*matrix)->down)
			break ;
		*matrix = (*matrix)->down;
	}
	while (*matrix)
	{
		if (ft_isalpha((*matrix)->letter))
			return ;
		if (!(*matrix)->right)
			break ;
		*matrix = (*matrix)->right;
	}
}

int		delete_row(t_map **matrix, t_map **map, t_list_matrix **stack, int one)
{
	char	symb;
	t_map	*tmp;
	int		d_rows;

	find_row(matrix, one);
	symb = (*matrix)->letter;
	fillmap_2(map, *matrix);
	find_matrix(matrix, 1, 1);
	tmp = *matrix;
	d_rows = 0;
	while (tmp)
	{
		if (tmp->letter == symb)
			d_rows += find_letter_in_col(matrix, symb, tmp, stack);
		if (!tmp->right)
			break ;
		tmp = tmp->right;
	}
	d_rows += delete_letters(matrix, stack, symb);
	return (d_rows);
}
