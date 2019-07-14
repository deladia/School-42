/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:33:39 by deladia           #+#    #+#             */
/*   Updated: 2019/07/10 20:33:47 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ipart(double x)
{
	return ((int)x);
}

int		ft_round(double x)
{
	return (ipart(x + 0.5));
}

double	fpart(double x)
{
	return (x - (int)x);
}

void	ft_swap(double *a, double *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_fdf(t_rec *r, t_param *p)
{
	if (((r->x1 == r->x2) && (r->y2 < r->y1))
		|| ((r->y1 == r->y2) && (r->x2 < r->x1))
		|| ((p->dy < p->dx) && (r->x2 < r->x1))
		|| ((p->dy >= p->dx) && (r->y2 < r->y1)))
	{
		ft_swap(&r->x1, &r->x2);
		ft_swap(&r->y1, &r->y2);
	}
	p->dx = r->x2 - r->x1;
	p->dy = r->y2 - r->y1;
}
