/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:35:18 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/08 18:37:37 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_1(char *buf)
{
	int	i;
	int	hash;
	int	endl;

	i = 0;
	endl = 0;
	hash = 0;
	while (buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (-1);
		if (buf[i] == '#')
			hash++;
		if (buf[i] == '\n')
			endl++;
		i++;
	}
	i++;
	if (i == 21 && i++)
		endl++;
	if (i - 10 != 12 || hash != 4 || endl != 5 ||
		buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		return (-1);
	return (0);
}

int		valid_2(char *buf, int i, int j)
{
	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (i < 15)
				if (buf[i + 5] == '#')
					j++;
			if (i >= 5)
				if (buf[i - 5] == '#')
					j++;
			if (i >= 1)
				if (buf[i - 1] == '#')
					j++;
			if (i < 20)
				if (buf[i + 1] == '#')
					j++;
		}
		i++;
	}
	if (j == 6 || j == 8)
		return (0);
	return (-1);
}
