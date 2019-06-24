#include "fdf.h"

void	draw_map(t_ptr *ptr, t_coor *map)
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
				draw_line(ptr_right->x * 10, ptr_right->y * 10, ptr_right->right->x * 10, ptr_right->right->y * 10, ptr);
			if (ptr_right->down)
				draw_line(ptr_right->x * 10, ptr_right->y * 10, ptr_right->down->x * 10, ptr_right->down->y * 10, ptr);
			if (!(ptr_right->right))
				break ;
			ptr_right = ptr_right->right;
		}
		if (!(ptr_down->down))
			break ;
		ptr_down = ptr_down->down;
	}
}