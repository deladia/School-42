/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_fig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:25:02 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/08 11:30:39 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete_fig2(t_map **map, int side, char c)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i <= side)
	{
		j = 1;
		while (j <= side)
		{
			find(map, i, j);
			if ((*map)->letter == c)
				(*map)->letter = '.';
			j++;
		}
		i++;
	}
}

void	ft_del_fig_right(t_map **map, t_list_fig **list)
{
	if (!(*map)->right && (*list)->figure->right)
		return ;
	else if ((*list)->figure->right &&
		(*list)->figure->right->hash == (*map)->right->letter)
	{
		*map = (*map)->right;
		(*list)->figure = (*list)->figure->right;
		ft_delete_fig(map, list);
		*map = (*map)->left;
		(*list)->figure = (*list)->figure->left;
	}
}

void	ft_del_fig_down(t_map **map, t_list_fig **list)
{
	if (!(*map)->down && (*list)->figure->down)
		return ;
	else if ((*list)->figure->down &&
		(*list)->figure->down->hash == (*map)->down->letter)
	{
		*map = (*map)->down;
		(*list)->figure = (*list)->figure->down;
		ft_delete_fig(map, list);
		*map = (*map)->up;
		(*list)->figure = (*list)->figure->up;
	}
}

void	ft_del_fig_left(t_map **map, t_list_fig **list)
{
	if (!(*map)->left && (*list)->figure->left)
		return ;
	else if ((*list)->figure->left &&
		(*list)->figure->left->hash == (*map)->left->letter)
	{
		*map = (*map)->left;
		(*list)->figure = (*list)->figure->left;
		ft_delete_fig(map, list);
		*map = (*map)->right;
		(*list)->figure = (*list)->figure->right;
	}
}

void	ft_delete_fig(t_map **map, t_list_fig **list)
{
	if ((*map)->letter == (*list)->figure->hash)
		(*map)->letter = '.';
	ft_del_fig_right(map, list);
	ft_del_fig_down(map, list);
	ft_del_fig_left(map, list);
	if (!(*map)->up && (*list)->figure->up)
		return ;
	else if ((*list)->figure->up &&
		(*list)->figure->up->hash == (*map)->up->letter)
	{
		*map = (*map)->up;
		(*list)->figure = (*list)->figure->up;
		ft_delete_fig(map, list);
		*map = (*map)->down;
		(*list)->figure = (*list)->figure->down;
	}
}
