#include "fdf.h"

void	ft_swap(int *a, int *b)
{
	int 	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	plot(int x, int y, double c, t_ptr *ptr)
{
	double 	color;

	color = 0xCC0000;
	color *= c;
	ptr->arr[x + y * (ptr->side_x)] = (int)color;
}

int 	ipart(double x)
{
	return ((int)x);
}

int 	ft_round(double x)
{
	return (ipart(x + 0.5));
}

double	fpart(double x)
{
	return(x - (int)x);
}

t_ptr	*draw_line(int x1, int y1, int x2, int y2, t_ptr *ptr)
{
	int 	dx;
	int 	dy;
	double 	gradient;
	double 	xend;
	double	yend;
	double 	xgap;
	double	ygap;
	int 	xpxl1;
	int 	ypxl1;
	double 	intery;
	int 	xpxl2;
	int 	ypxl2;
	int 	i;

	dx = (x2 > x1) ? (x2 - x1) : (x1 - x2);
	dy = (y2 > y1) ? (y2 - y1) : (y1 - y2);
	if (x1 == x2)
	{
		if (y2 < y1)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		while (y1 != y2)
		{
			plot(x1, y1, 1, ptr);
			y1++;
		}
	}
	else if (y1 == y2)
	{
		if (x2 < x1)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		while (x1 != x2)
		{
			plot(x1, y1, 1, ptr);
			x1++;
		}
	}
	else if (dy < dx)
	{
		if (x2 < x1)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		gradient = (double) dy / dx;

		xend = ft_round((double)x1);
		yend = (double) y1 + gradient * (xend - x1);
		xgap = 1.0 - fpart(x1 + 0.5);
		xpxl1 = (int) xend;
		ypxl1 = ipart(yend);
		plot(xpxl1, ypxl1, (1.0 - fpart(yend)) * xgap, ptr);
		plot(xpxl1, ypxl1 + 1, fpart(yend) * xgap, ptr);
		intery = yend + gradient;

		xend = ft_round((double)x2);
		yend = y2 + gradient * (xend - x2);
		xgap = fpart(x2 + 0.5);
		xpxl2 = (int) xend;
		ypxl2 = ipart(yend);
		plot(xpxl2, ypxl2, (1.0 - fpart(yend)) * xgap, ptr);
		plot(xpxl2, ypxl2 + 1, fpart(yend) * xgap, ptr);
		i = xpxl1;
		while (i <= xpxl2 - 1)
		{
			plot(i, ipart(intery), 1.0 - fpart(intery), ptr);
			plot(i, ipart(intery) + 1, fpart(intery), ptr);
			intery = intery + gradient;
			i++;
		}
	}
	else
	{
		if (y2 < y1)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		gradient = (double) dx / dy;

		xend = ft_round((double)x1);
		yend = (double) y1 + gradient * (xend - x1);
		ygap = 1.0 - fpart(y1 + 0.5);
		xpxl1 = (int) xend;
		ypxl1 = ipart(yend);
		plot(xpxl1, ypxl1, (1.0 - fpart(yend)) * ygap, ptr);
		plot(xpxl1 + 1, ypxl1, fpart(yend) * ygap, ptr);
		intery = yend + gradient;

		xend = ft_round((double)x2);
		yend = y2 + gradient * (xend - x2);
		ygap = fpart(x2 + 0.5);
		xpxl2 = (int) xend;
		ypxl2 = ipart(yend);
		plot(xpxl2, ypxl2, (1.0 - fpart(yend)) * ygap, ptr);
		plot(xpxl2 + 1, ypxl2, fpart(yend) * ygap, ptr);
		i = ypxl1;
		while (i <= ypxl2 - 1)
		{
			plot(ipart(intery), i, 1.0 - fpart(intery), ptr);
			plot(ipart(intery) + 1, i, fpart(intery), ptr);
			intery = intery + gradient;
			i++;
		}
	}
	return (ptr);
	//mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}