/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:38:14 by deladia           #+#    #+#             */
/*   Updated: 2019/06/07 21:00:21 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*create_cell(int x, int y)
{
	t_map		*new_cell;

	new_cell = (t_map *)ft_memalloc(sizeof(t_map));
	new_cell->x = x;
	new_cell->y = y;
	new_cell->letter = '.';
	return (new_cell);
}

void		link_right_left(t_map **map, int x, int y)
{
	t_map		*new_cell;

	new_cell = (t_map *)ft_memalloc(sizeof(t_map));
	(*map)->right = new_cell;
	new_cell->left = *map;
	new_cell->x = x;
	new_cell->y = y;
	new_cell->letter = '.';
	*map = (*map)->right;
}

void		link_up_down(t_map **map, t_map **second, int y)
{
	while (y >= 1)
	{
		(*map)->down = *second;
		(*second)->up = *map;
		if ((*map)->left && (*second)->left)
		{
			*map = (*map)->left;
			*second = (*second)->left;
		}
		y--;
	}
	while ((*second)->right)
		*second = (*second)->right;
	*map = *second;
}

void		create_map(t_map **map, int a)
{
	int		x;
	int		y;
	t_map	*second;

	x = 1;
	y = 1;
	*map = create_cell(x, y);
	while (x < a)
	{
		y = 1;
		second = create_cell(x + 1, y);
		while (y < a)
		{
			if (x == 1)
				link_right_left(map, x, y + 1);
			link_right_left(&second, x + 1, y + 1);
			y++;
		}
		link_up_down(map, &second, y);
		x++;
	}
	find(map, 1, 1);
}
