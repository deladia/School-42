#include "fdf.h"

void	iso(t_coor *coor, t_fdf *ptr)
{
	double	previous_x;
	double 	previous_y;

	previous_x = coor->x;
	previous_y = coor->y;
	ptr->angle = 0.523599;
	coor->x = (previous_x - previous_y) * cos(ptr->angle);
	coor->y = (previous_x + previous_y) * sin(ptr->angle) - coor->z;
}

void 	rotate_iso(t_coor *map, t_fdf *ptr)
{
	t_coor	*x;
	t_coor	*y;

	y = map;
	while (y)
	{
		x = y;
		while (x)
		{
			x->x = x->x * 10;
			x->y = x->y * 10;
			x->z = x->z * 3;
			iso(x, ptr);
			if (!(x->right))
				break ;
			x = x->right;
		}
		if (!(y->down))
			break ;
		y = y->down;
	}
}

void	draw_map(t_fdf *ptr, t_coor *map)
{
	t_coor	*ptr_down;
	t_coor	*ptr_right;

	ptr_down = map;
	while (ptr_down)
	{
		ptr_right = ptr_down;
		while (ptr_right)
		{
			if (ptr_right->right)
				draw_line(ptr_right->x + ptr->x, ptr_right->y + ptr->y, ptr_right->right->x + ptr->x, ptr_right->right->y + ptr->y, ptr);
			if (ptr_right->down)
				draw_line(ptr_right->x + ptr->x, ptr_right->y + ptr->y, ptr_right->down->x + ptr->x, ptr_right->down->y + ptr->y, ptr);
			if (!(ptr_right->right))
				break ;
			ptr_right = ptr_right->right;
		}
		if (!(ptr_down->down))
			break ;
		ptr_down = ptr_down->down;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}