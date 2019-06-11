/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:29:18 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/08 12:44:13 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_matrix(t_struct **str)
{
	while ((*str)->list->prev)
		(*str)->list = (*str)->list->prev;
	while ((*str)->list)
	{
		(*str)->side = insert_fig(str);
		if (!(*str)->list->next)
			break ;
		(*str)->list = (*str)->list->next;
	}
	return ((*str)->side);
}

int		cnt_row_with_letter(t_map *matrix, char letter, int i)
{
	t_map	*ptr;

	i = 0;
	find_matrix(&matrix, 1, 1);
	while (matrix->up)
		matrix = matrix->up;
	while (matrix)
	{
		ptr = matrix;
		while (ptr->right)
		{
			if (ft_isalpha(ptr->letter) && ptr->letter != letter)
				return (i);
			if (ptr->letter == letter)
			{
				i++;
				break ;
			}
			ptr = ptr->right;
		}
		if (!matrix->down)
			break ;
		matrix = matrix->down;
	}
	return (i);
}

void	ft_if(t_struct **str, t_list_matrix **stack, t_temp temp)
{
	(*str)->side++;
	(*str)->matrix = NULL;
	add_col(&(*str)->map);
	add_row(&(*str)->map);
	create_matrix(str);
	force(str, stack, temp);
}

int		force2(t_struct **str, t_list_matrix **stack, t_temp temp)
{
	t_vars_f	var;

	find_row(&(*str)->matrix, 1);
	var.letter = (*str)->matrix->letter;
	var.i = 1;
	var.j = cnt_row_with_letter((*str)->matrix, var.letter, var.i);
	while (var.i <= var.j)
	{
		var.d_rows = delete_row(&(*str)->matrix,
		&(*str)->map, stack, var.i);
		temp.cnt_fig--;
		temp.flag++;
		var.key = force(str, stack, temp);
		temp.flag--;
		if (var.key == 1)
			return (var.key);
		var.i++;
		if (var.key == 0)
		{
			temp.cnt_fig++;
			ft_delete_fig2(&(*str)->map, (*str)->side, var.letter);
			(*str)->matrix = restore_all_in_stack(stack, var.d_rows);
		}
	}
	return (var.key);
}

int		force(t_struct **str, t_list_matrix **stack, t_temp temp)
{
	int	key;

	key = 0;
	if (temp.cnt_fig == 0 && (*str)->matrix == NULL)
		return (1);
	if (temp.cnt_fig != 0 && (*str)->matrix == NULL)
		return (0);
	key = force2(str, stack, temp);
	if (key != 1 && temp.flag == 0)
		ft_if(str, stack, temp);
	return (key);
}
