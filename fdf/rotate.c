#include "fdf.h"
#include <math.h>

void	iso(t_coor *coor)
{
	int previous_x;
	int previous_y;

	previous_x = coor->x;
	previous_y = coor->y;
	coor->x = (previous_x - previous_y) * cos(0.523599);
	coor->y = (-1 * coor->z) + (previous_x + previous_y) * sin(0.523599);
}

t_ptr	*draw_map(t_ptr *ptr, t_arr *array)
{
	int 	i;
	int 	j;
	t_coor	*coor1;
	t_coor	*coor2;
	t_coor	*coor3;
	t_coor	*coor4;

	coor1 = (t_coor *)ft_memalloc(sizeof(t_coor));
	coor2 = (t_coor *)ft_memalloc(sizeof(t_coor));
	coor3 = (t_coor *)ft_memalloc(sizeof(t_coor));
	coor4 = (t_coor *)ft_memalloc(sizeof(t_coor));

	i = 0;
	coor2->x = 0;
	coor2->y = 0;
	coor2->z = 0;
	while (i < array->cnt_row)
	{
		j = 0;
		while (j < array->cnt_col)
		{
			if (i == 0 && j == 0)
			{
				j++;
				continue;
			}
			if (j == array->cnt_col - 1)
			{
				coor1->x = coor2->x;
				coor1->y = coor2->y;
				coor1->z = coor2->z;

				coor4->x = (j - 1) * 30;
				coor4->y = (i + 1) * 30;
				coor4->z = array->arr[i][j] * 5;

//				iso(coor1);
//				iso(coor4);

				draw_line(coor1->x, coor1->y, coor4->x, coor4->y, ptr);
			}
			else
			{
				coor1->x = coor2->x; //max
				coor1->y = coor2->y; //0
				coor1->z = coor2->z;

				coor2->x = j * 30;	// 0
				coor2->y = i * 30;  // 1
				coor2->z = array->arr[i][j] * 5;

				coor4->x = (j - 1) * 30;
				coor4->y = (i + 1) * 30;
				coor4->z = array->arr[i][j] * 5;

//				iso(coor1);
//				iso(coor2);
//				iso(coor3);
//				iso(coor4);

				draw_line(coor1->x, coor1->y, coor2->x, coor2->y, ptr);
				draw_line(coor1->x, coor1->y, coor4->x, coor4->y, ptr);
			}
//			coor2->x = j * 30;
//			coor2->y = i * 30;
//			coor2->z = array->arr[i][j] * 5;
			j++;
		}
		i++;
	}
	return (ptr);
}