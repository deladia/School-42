/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:28:46 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/08 11:58:59 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find(t_map **m, int x, int y)
{
	while ((*m)->y != y)
	{
		if ((*m)->y > y)
			*m = (*m)->left;
		else if ((*m)->y < y)
			*m = (*m)->right;
	}
	while ((*m)->x != x)
	{
		if ((*m)->x > x)
			*m = (*m)->up;
		else if ((*m)->x < x)
			*m = (*m)->down;
	}
}

void	print_map(t_map **m, int side)
{
	t_map	*ptr;
	int		i;
	int		j;

	i = 1;
	j = 1;
	find(m, 1, 1);
	ptr = *m;
	while (i <= side)
	{
		j = 1;
		while (j <= side)
		{
			find(m, i, j);
			ptr = *m;
			write(1, &ptr->letter, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
