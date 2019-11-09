/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:17:18 by deladia           #+#    #+#             */
/*   Updated: 2019/10/08 01:56:17 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*clear_array(t_fdf *ptr)
{
	int		i;

	i = 0;
	while (i <= (SIDE_X * SIDE_Y))
	{
		ptr->arr[i] = 0x000000;
		i++;
	}
	return (ptr->arr);
}

t_rec	*ft_recount(t_coor *coor1, t_coor *coor2, t_rec *rec, t_fdf *fdf)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = coor1->x * fdf->coef;
	y1 = coor1->y * fdf->coef;
	x2 = coor2->x * fdf->coef;
	y2 = coor2->y * fdf->coef;
	rec->x1 = x1 * cos(fdf->ygl) - y1 * sin(fdf->ygl);
	rec->y1 = x1 * sin(fdf->ygl) + y1 * cos(fdf->ygl);
	rec->x2 = x2 * cos(fdf->ygl) - y2 * sin(fdf->ygl);
	rec->y2 = x2 * sin(fdf->ygl) + y2 * cos(fdf->ygl);
	x1 = (rec->x1 - rec->y1) * cos(fdf->angle);
	y1 = (rec->x1 + rec->y1) * sin(fdf->angle) - (double)coor1->z * fdf->coef;
	x2 = (rec->x2 - rec->y2) * cos(fdf->angle);
	y2 = (rec->x2 + rec->y2) * sin(fdf->angle) - (double)coor2->z * fdf->coef;
	rec->x1 = x1 + fdf->x;
	rec->y1 = y1 + fdf->y;
	rec->x2 = x2 + fdf->x;
	rec->y2 = y2 + fdf->y;
	return (rec);
}

void	draw_map_1(t_coor *ptr_right, t_rec *rec, t_fdf *ptr)
{
	while (ptr_right)
	{
		if (ptr_right->right)
		{
			rec = ft_recount(ptr_right, ptr_right->right, rec, ptr);
			draw_line(rec, ptr);
		}
		if (ptr_right->down)
		{
			rec = ft_recount(ptr_right, ptr_right->down, rec, ptr);
			draw_line(rec, ptr);
		}
		if (!(ptr_right->right))
			break ;
		ptr_right = ptr_right->right;
	}
}

void	draw_map(t_fdf *ptr, t_coor *map)
{
	t_coor	*ptr_down;
	t_coor	*ptr_right;
	t_rec	*rec;

	rec = (t_rec *)ft_memalloc(sizeof(t_rec));
	ptr_down = map;
	while (ptr_down)
	{
		ptr_right = ptr_down;
		draw_map_1(ptr_right, rec, ptr);
		if (!(ptr_down->down))
			break ;
		ptr_down = ptr_down->down;
	}
	free(rec);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}
