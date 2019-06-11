/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 00:18:50 by deladia           #+#    #+#             */
/*   Updated: 2019/06/08 10:54:24 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	link_right_left_2(t_map **m, t_map *ptr, int x, int y)
{
	while (*m)
	{
		y++;
		ptr->right = create_cell(x + 1, y);
		ptr->right->left = ptr;
		ptr->right->up = *m;
		(*m)->down = ptr->right;
		ptr = ptr->right;
		if (!(*m)->right)
			break ;
		*m = (*m)->right;
	}
}

void	link_up_down_2(t_map **m, t_map *ptr, int x, int y)
{
	while (*m)
	{
		x++;
		ptr->down = create_cell(x, y + 1);
		ptr->down->up = ptr;
		ptr->down->left = *m;
		(*m)->right = ptr->down;
		ptr = ptr->down;
		if (!(*m)->down)
			break ;
		*m = (*m)->down;
	}
}

void	add_row(t_map **m)
{
	t_map	*ptr;
	int		x;
	int		y;

	x = 1;
	y = 1;
	find(m, 1, 1);
	ptr = *m;
	while (ptr->down)
	{
		ptr = ptr->down;
		x++;
	}
	ptr->down = create_cell(x + 1, y);
	ptr->down->up = ptr;
	ptr = ptr->down;
	find(m, x, 2);
	link_right_left_2(m, ptr, x, y);
}

void	add_col(t_map **m)
{
	t_map	*ptr;
	int		x;
	int		y;

	x = 1;
	y = 1;
	find(m, 1, 1);
	ptr = *m;
	while (ptr->right)
	{
		ptr = ptr->right;
		y++;
	}
	ptr->right = create_cell(x, y + 1);
	ptr->right->left = ptr;
	ptr = ptr->right;
	find(m, 2, y);
	link_up_down_2(m, ptr, x, y);
}
