/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:57:40 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/05/22 19:48:45 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		create_fig(t_fig **fig, int i, char letter)
{
	t_fig		*new;

	if (!*fig)
	{
		*fig = (t_fig *)ft_memalloc(sizeof(t_fig));
		(*fig)->right = NULL;
		(*fig)->left = NULL;
	}
	else
	{
		new = (t_fig *)ft_memalloc(sizeof(t_fig));
		(*fig)->right = new;
		new->left = *fig;
		*fig = new;
	}
	(*fig)->up = NULL;
	(*fig)->down = NULL;
	(*fig)->i = i;
	(*fig)->hash = letter;
}

void		store_fig(t_list_fig **list, char *buf, char letter)
{
	size_t		i;
	t_fig		*fig;

	i = 0;
	fig = NULL;
	while (buf[i])
	{
		if (buf[i] == '#')
			create_fig(&fig, i, letter);
		i++;
	}
	while (fig->left)
		fig = fig->left;
	link_hash(&fig);
	create_list(list, &fig);
}
