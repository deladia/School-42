/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:24:18 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/11 16:36:38 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_right(t_map **matrix)
{
	t_map *tmp;

	if (!(*matrix)->left)
		while (*matrix)
		{
			tmp = *matrix;
			if (!(*matrix)->right)
			{
				if (!(*matrix)->down)
				{
					free(tmp);
					tmp = NULL;
					*matrix = NULL;
					return ;
				}
				*matrix = (*matrix)->down;
				free(tmp);
				tmp = NULL;
				break ;
			}
			*matrix = (*matrix)->right;
			free(tmp);
			tmp = NULL;
		}
}

void	ft_free_left(t_map **matrix)
{
	t_map *tmp;

	if (!(*matrix)->right)
		while (*matrix)
		{
			tmp = *matrix;
			if (!(*matrix)->left)
			{
				if (!(*matrix)->down)
				{
					free(tmp);
					tmp = NULL;
					*matrix = NULL;
					return ;
				}
				*matrix = (*matrix)->down;
				free(tmp);
				tmp = NULL;
				break ;
			}
			*matrix = (*matrix)->left;
			free(tmp);
			tmp = NULL;
		}
}

void	ft_free(t_map **matrix)
{
	find_matrix(matrix, 1, 1);
	while ((*matrix)->up)
		*matrix = (*matrix)->up;
	while (*matrix)
	{
		ft_free_right(matrix);
		if (!matrix)
			return ;
		ft_free_left(matrix);
	}
}
