/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:41:41 by deladia           #+#    #+#             */
/*   Updated: 2019/10/08 01:54:19 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		plot(int x, int y, double c, t_fdf *ptr)
{
	int		color;
	int		red;
	int		green;
	int		blue;

	color = ptr->color;
	red = (color & 0xFF0000) >> 16;
	red = red * c;
	green = (color & 0x00FF00) >> 8;
	green = green * c;
	blue = (color & 0x0000FF);
	blue = blue * c;
	color = (red << 16) | (green << 8) | blue;
	if (x >= 0 && x < SIDE_X && y >= 0 && y < SIDE_Y)
		ptr->arr[x + y * (SIDE_X)] = (color);
	return (OK);
}

void	os_x(t_rec *r, t_param *p, t_fdf *ptr)
{
	int		i;

	ft_swap_fdf(r, p);
	p->gradient = (double)p->dy / p->dx;
	p->xend = ft_round((double)r->x1);
	p->yend = (double)r->y1 + p->gradient * (p->xend - r->x1);
	p->xgap = 1.0 - fpart(r->x1 + 0.5);
	p->xpxl1 = (int)p->xend;
	p->ypxl1 = ipart(p->yend);
	plot(p->xpxl1, p->ypxl1, (1.0 - fpart(p->yend)) * p->xgap, ptr);
	plot(p->xpxl1, p->ypxl1 + 1, fpart(p->yend) * p->xgap, ptr);
	p->intery = p->yend + p->gradient;
	p->xend = ft_round((double)r->x2);
	p->yend = r->y2 + p->gradient * (p->xend - r->x2);
	p->xgap = fpart(r->x2 + 0.5);
	p->xpxl2 = (int)p->xend;
	p->ypxl2 = ipart(p->yend);
	i = p->xpxl1 + plot(p->xpxl2, p->ypxl2, (1.0 - fpart(p->yend)) * p->xgap,
			ptr) + plot(p->xpxl2, p->ypxl2 + 1, fpart(p->yend) * p->xgap, ptr);
	while (i <= p->xpxl2 - 1)
	{
		plot(i, ipart(p->intery), 1.0 - fpart(p->intery), ptr);
		plot(i++, ipart(p->intery) + 1, fpart(p->intery), ptr);
		p->intery = p->intery + p->gradient;
	}
}

void	os_y(t_rec *r, t_param *p, t_fdf *ptr)
{
	int		i;

	ft_swap_fdf(r, p);
	p->gradient = (double)p->dx / p->dy;
	p->yend = ft_round((double)r->y1);
	p->xend = (double)r->x1 + p->gradient * (p->yend - r->y1);
	p->ygap = 1.0 - fpart(r->y1 + 0.5);
	p->xpxl1 = ipart(p->xend);
	p->ypxl1 = (int)p->yend;
	plot(p->xpxl1, p->ypxl1, (1.0 - fpart(p->yend)) * p->ygap, ptr);
	plot(p->xpxl1 + 1, p->ypxl1, fpart(p->yend) * p->ygap, ptr);
	p->intery = p->xend + p->gradient;
	p->yend = ft_round((double)r->y2);
	p->xend = r->x2 + p->gradient * (p->yend - r->y2);
	p->ygap = fpart(r->y2 + 0.5);
	p->xpxl2 = ipart(p->xend);
	p->ypxl2 = (int)p->yend;
	i = p->ypxl1 + plot(p->xpxl2, p->ypxl2, (1.0 - fpart(p->yend)) * p->ygap,
			ptr) + plot(p->xpxl2 + 1, p->ypxl2, fpart(p->yend) * p->ygap, ptr);
	while (i <= p->ypxl2 - 1)
	{
		plot(ipart(p->intery), i, 1.0 - fpart(p->intery), ptr);
		plot(ipart(p->intery) + 1, i++, fpart(p->intery), ptr);
		p->intery = p->intery + p->gradient;
	}
}

t_fdf	*draw_line(t_rec *r, t_fdf *ptr)
{
	t_param		*p;

	p = (t_param *)ft_memalloc(sizeof(t_param));
	p->dx = (r->x2 > r->x1) ? (int)(r->x2 - r->x1) : (int)(r->x1 - r->x2);
	p->dy = (r->y2 > r->y1) ? (int)(r->y2 - r->y1) : (int)(r->y1 - r->y2);
	if (r->x1 == r->x2)
	{
		ft_swap_fdf(r, p);
		while (r->y1 != r->y2)
			plot((int)r->x1, (int)r->y1++, 1, ptr);
	}
	else if (r->y1 == r->y2)
	{
		ft_swap_fdf(r, p);
		while (r->x1 != r->x2)
			plot((int)r->x1++, (int)r->y1, 1, ptr);
	}
	else if (p->dy < p->dx)
		os_x(r, p, ptr);
	else
		os_y(r, p, ptr);
	free(p);
	return (ptr);
}
