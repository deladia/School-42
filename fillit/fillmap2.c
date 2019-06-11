/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:07:55 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/07 18:22:57 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillmap_2(t_map **map, t_map *matrix)
{
	int i;

	i = 0;
	while (matrix)
	{
		if (ft_isalpha(matrix->letter))
		{
			find(map, matrix->x, matrix->y);
			(*map)->letter = matrix->letter;
			i++;
		}
		if (i == 4)
			return ;
		if (!matrix->right)
			break ;
		matrix = matrix->right;
	}
}
