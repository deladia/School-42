#include "fdf.h"

void 		get_color(t_coor *c1, t_coor *c2, t_fdf *fdf)
{
	double	delta;

	if (c1->z == c2->z)
	{
		if (c1->z < 0)
			fdf->color = 0x007FFF;
		else if (c1->z / 10)
			fdf->color = 0x8DB600;
		else if (c1->z / 50)
			fdf->color = 0x4B5320;
		else if (c1->z / 100)
			fdf->color = 0x964B00;
	}
	else
	{
		delta = (c1->z > c2->z) ? c1->z - c2->z : c2->z - c1->z;

	}
}

t_recount	*ft_recount(t_coor *coor1, t_coor *coor2, t_recount *rec, t_fdf *fdf)
{
	double 	x1;
	double 	y1;
	double 	x2;
	double 	y2;

	x1 = coor1->x * fdf->coef;
	y1 = coor1->y * fdf->coef;
	x2 = coor2->x * fdf->coef;
	y2 = coor2->y * fdf->coef;
	rec->x1 = x1 * cos(fdf->ygl) - y1 * sin(fdf->ygl);
	rec->y1 = x1 * sin(fdf->ygl) + y1 * cos(fdf->ygl);
	rec->x2 = x2 * cos(fdf->ygl) - y2 * sin(fdf->ygl);
	rec->y2 = x2 * sin(fdf->ygl) + y2 * cos(fdf->ygl);
	x1 = (rec->x1 - rec->y1) * cos(fdf->angle);
	y1 = (rec->x1 + rec->y1) * sin(fdf->angle) - coor1->z * fdf->coef / 2;
	x2 = (rec->x2 - rec->y2) * cos(fdf->angle);
	y2 = (rec->x2 + rec->y2) * sin(fdf->angle) - coor2->z * fdf->coef / 2;
	rec->x1 = x1;
	rec->y1 = y1;
	rec->x2 = x2;
	rec->y2 = y2;
//	get_color(coor1, coor2, fdf);
	return (rec);
}

void		draw_map(t_fdf *ptr, t_coor *map)
{
	t_coor		*ptr_down;
	t_coor		*ptr_right;
	t_recount	*rec;

	rec = (t_recount *)ft_memalloc(sizeof(t_recount));
	ptr_down = map;
	while (ptr_down)
	{
		ptr_right = ptr_down;
		while (ptr_right)
		{
			if (ptr_right->right)
			{
				rec = ft_recount(ptr_right, ptr_right->right, rec, ptr);
				draw_line(rec->x1 + ptr->x, rec->y1 + ptr->y, rec->x2 + ptr->x, rec->y2 + ptr->y, ptr);
			}
			if (ptr_right->down)
			{
				rec = ft_recount(ptr_right, ptr_right->down, rec, ptr);
				draw_line(rec->x1 + ptr->x, rec->y1 + ptr->y, rec->x2 + ptr->x, rec->y2 + ptr->y, ptr);
			}
			if (!(ptr_right->right))
				break ;
			ptr_right = ptr_right->right;
		}
		if (!(ptr_down->down))
			break ;
		ptr_down = ptr_down->down;
	}
	free(rec);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}