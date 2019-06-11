/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:44:37 by deladia           #+#    #+#             */
/*   Updated: 2019/06/08 11:31:15 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillmap_right(t_map **map, t_list_fig **list, int ret)
{
	if (!(*map)->right && (*list)->figure->right)
		return (0);
	else if ((*list)->figure->right &&
		(*list)->figure->right->hash != (*map)->right->letter)
	{
		*map = (*map)->right;
		(*list)->figure = (*list)->figure->right;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		*map = (*map)->left;
		(*list)->figure = (*list)->figure->left;
	}
	return (ret);
}

int		ft_fillmap_down(t_map **map, t_list_fig **list, int ret)
{
	if (!(*map)->down && (*list)->figure->down)
		return (0);
	else if ((*list)->figure->down &&
		(*list)->figure->down->hash != (*map)->down->letter)
	{
		*map = (*map)->down;
		(*list)->figure = (*list)->figure->down;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		*map = (*map)->up;
		(*list)->figure = (*list)->figure->up;
	}
	return (ret);
}

int		ft_fillmap_left(t_map **map, t_list_fig **list, int ret)
{
	if (!(*map)->left && (*list)->figure->left)
		return (0);
	else if ((*list)->figure->left &&
		(*list)->figure->left->hash != (*map)->left->letter)
	{
		*map = (*map)->left;
		(*list)->figure = (*list)->figure->left;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		*map = (*map)->right;
		(*list)->figure = (*list)->figure->right;
	}
	return (ret);
}

int		ft_fillmap(t_map **map, t_list_fig **list)
{
	int ret;

	ret = 1;
	if ((*map)->letter != (*list)->figure->hash)
		(*map)->letter = (*list)->figure->hash;
	ret = ft_fillmap_right(map, list, ret);
	ret = ft_fillmap_down(map, list, ret);
	ret = ft_fillmap_left(map, list, ret);
	if (!(*map)->up && (*list)->figure->up)
		return (0);
	else if ((*list)->figure->up &&
		(*list)->figure->up->hash != (*map)->up->letter)
	{
		*map = (*map)->up;
		(*list)->figure = (*list)->figure->up;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		*map = (*map)->down;
		(*list)->figure = (*list)->figure->down;
	}
	return (ret);
}
