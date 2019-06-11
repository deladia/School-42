/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:39:59 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/11 15:19:29 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		link_hash_plus(t_fig **l1, t_fig **l2)
{
	if (((*l1)->i + 5) == (*l2)->i)
	{
		(*l1)->down = (*l2);
		(*l2)->up = (*l1);
	}
	if (((*l1)->i + 1) == (*l2)->i)
	{
		(*l1)->right = (*l2);
		(*l2)->left = (*l1);
	}
}

void		link_hash_minus(t_fig **l1, t_fig **l2)
{
	if (((*l2)->i - 5) == (*l1)->i)
	{
		(*l2)->up = (*l1);
		(*l1)->down = (*l2);
	}
	if (((*l2)->i - 1) == (*l1)->i)
	{
		(*l1)->right = (*l2);
		(*l2)->left = (*l1);
	}
}

void		link_hash(t_fig **fig)
{
	t_fig *h1;
	t_fig *h2;
	t_fig *h3;
	t_fig *h4;

	h1 = *fig;
	h2 = (*fig)->right;
	h3 = (*fig)->right->right;
	h4 = (*fig)->right->right->right;
	h1->right = NULL;
	h2->right = NULL;
	h2->left = NULL;
	h3->right = NULL;
	h3->left = NULL;
	h4->right = NULL;
	h4->left = NULL;
	link_hash_plus(&h1, &h2);
	link_hash_plus(&h1, &h3);
	link_hash_plus(&h1, &h4);
	link_hash_plus(&h2, &h3);
	link_hash_minus(&h3, &h2);
	link_hash_minus(&h2, &h4);
	link_hash_minus(&h3, &h4);
	*fig = h1;
}
