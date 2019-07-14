#include "fractol.h"

int		*clear_array(t_fractol *fract)
{
	int		i;

	i = 0;
	while (i <= (SIDE_X * SIDE_Y))
	{
		fract->arr[i] = 0x000000;
		i++;
	}
	return (fract->arr);
}

//int		mouse_move(int x, int y, t_fractol *ptr)
//{
//	ptr->arr = clear_array(ptr);
//	if (ptr->flag == 1)
//	{
//		ptr->x -= ptr->mouse_x - x;
//		ptr->y -= (ptr->mouse_y - y);
//		ptr->mouse_x = x;
//		ptr->mouse_y = y;
//	}
//	draw_map(ptr, ptr->map);
//	return (OK);
//}

//int		mouse_press(int button, int x, int y, t_fdf *ptr)
//{
//	ptr->arr = clear_array(ptr);
//	if (button == 4)
//		ptr->coef += 1;
//	if (button == 5 && ptr->coef != 0)
//		ptr->coef -= 1;
//	if (button == 1)
//	{
//		ptr->flag *= -1;
//		ptr->mouse_x = x;
//		ptr->mouse_y = y;
//	}
////	draw_map(ptr, ptr->map);
//	return (0);
//}

int		key_press_1(int keycode, t_fractol *ptr)
{
	if (keycode == 34)
	{
		ptr->angle = 0.523599;
		ptr->ygl = 0;
	}
	if (keycode == 6)
		ptr->ygl += 0.03;
	if (keycode == 7)
		ptr->ygl -= 0.03;
	if (keycode == 47)
		ptr->color += 255;
	if (keycode == 43)
		ptr->color -= 255;
	return (0);
}

int		key_press(int keycode, t_fractol *ptr)
{
	ptr->arr = clear_array(ptr);
	if (keycode == 53)
		exit(0);
//	if (keycode == 0)
//		ptr->x -= 10;
//	if (keycode == 1)
//		ptr->y += 10;
//	if (keycode == 2)
//		ptr->x += 10;
//	if (keycode == 13)
//		ptr->y -= 10;
//	if (keycode == 12)
//		ptr->angle += 0.03;
//	if (keycode == 14)
//		ptr->angle -= 0.03;
//	key_press_1(keycode, ptr);
//	draw_map(ptr, ptr->map);
	return (0);
}

int		close(int param)
{
	(void)param;
	exit(0);
}

t_fractol		*recount(t_fractol *fract)
{
	double		xc;
	double 		yc;
	int 		x;
	int			y;
	int 		i;
	double 		xn1;
	double		yn1;
	double 		xn0;
	double 		yn0;

	y = 0;
	while(y < SIDE_Y)
	{
		x = 0;
		while(x < SIDE_X)
		{
			xc = 0.002 * x - 2;
			yc = -0.002 * y + 1;
			xn0 = 0;
			yn0 = 0;
			i = 0;
			while (i++ < 100)
			{
				xn1 = xn0 * xn0 - yn0 * yn0 + xc;
				yn1 = 2 * xn0 * yn0 + yc;
				xn0 = xn1;
				yn0 = yn1;
				//проверять сходимость при каждой итерации, если расходится, то брейк
			}

//			printf("%f %f ", xn1, yn1);
			if ((xn1 * xn1 + yn1 * yn1) <= 4)
				fract->arr[y * SIDE_X + x] = 0x000000;
			else
				fract->arr[y * SIDE_X + x] = 0xFFFFFF;
			x++;
		}
		y++;
	}
	return (fract);
}

void	control(t_fractol *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, SIDE_X, SIDE_Y, "window");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, SIDE_X, SIDE_Y);
	fract->arr = (int *)mlx_get_data_addr(fract->img_ptr,
										&fract->bit_per_pixel, &fract->size_line, &fract->endian);
//	draw_map(fdf, map);
	recount(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
	mlx_hook(fract->win_ptr, 2, 0, key_press, fract);
//	mlx_hook(fract->win_ptr, 4, 0, mouse_press, fract);
//	mlx_hook(fract->win_ptr, 6, 0, mouse_move, fract);
	mlx_hook(fract->win_ptr, 17, 0, close, 0);
	mlx_loop(fract->mlx_ptr);
}

int		main(void)
{
	t_fractol	*fract;

	if (!(fract = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (1);
	control(fract);

	return (0);
}
