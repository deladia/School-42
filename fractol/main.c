#include "fractol.h"

int		*clear_array(t_fractol *fract)
{
	int		i;

	i = 0;
	while (i <= (SIDE_X * SIDE_Y))
	{
		fract->arr[i] = 0xFFFFFF;
		i++;
	}
	return (fract->arr);
}

void	fractol_free(t_fractol **fract)
{
	free((*fract)->cl);
	free((*fract)->program_source);
	free(*fract);
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

int		mouse_press(int button, int x, int y, t_fractol *fract)
{
	fract->arr = clear_array(fract);
	if (button == 4)
	{
		fract->xmin = 0;
		fract->ymin = 0;
		fract->xmax = 0;
		fract->ymax = 0;
		printf("xmin=%f | xmax=%f | ymin=%f | ymax=%f\n", fract->xmin, fract->xmax, fract->ymin, fract->ymax);
	}
	if (button == 5 && fract->xmin != 0)
	{
		fract->xmin = 0;
		fract->ymin = 0;
		fract->xmax = 0;
		fract->ymax = 0;
		printf("xmin=%f | xmax=%f | ymin=%f | ymax=%f\n", fract->xmin, fract->xmax, fract->ymin, fract->ymax);
	}
	set_arg(fract, fract->cl);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
	return (OK);
}

int		key_press_1(int keycode, t_fractol *fract)
{
	if (keycode == 18)
		fract->color = 0;
	if (keycode == 19)
		fract->color = 15;
	if (keycode == 20)
		fract->color = 30;
	if (keycode == 21)
		fract->color = 45;
	if (keycode == 23)
		fract->color = 55;
	if (keycode == 22)
		fract->color = 65;
	if (keycode == 26)
		fract->color = 75;
	if (keycode == 28)
		fract->color = 230;
	if (keycode == 25)
		fract->color = 251;
	return (OK);
}

int		key_press(int keycode, t_fractol *fract)
{
	fract->arr = clear_array(fract);
	if (keycode == 53)
	{
		fractol_free(&fract);
		exit(OK);
	}
	if (keycode == 0)
		fract->x -= 10;
	if (keycode == 1)
		fract->y += 10;
	if (keycode == 2)
		fract->x += 10;
	if (keycode == 13)
		fract->y -= 10;
	if (keycode == 69)
		fract->repeat += 1;
	if (keycode == 78 && fract->repeat > 1)
		fract->repeat -= 1;
	key_press_1(keycode, fract);
	set_arg(fract, fract->cl);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
	return (OK);
}

int		close(int param)
{
	(void)param;
	exit(OK);
}

void	control(t_fractol *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, SIDE_X, SIDE_Y, "window");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, SIDE_X, SIDE_Y);
	fract->arr = (int *)mlx_get_data_addr(fract->img_ptr,
										&fract->bit_per_pixel, &fract->size_line, &fract->endian);
	clear_array(fract);
	create_cl(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
	mlx_hook(fract->win_ptr, 2, 0, key_press, fract);
//	mlx_hook(fract->win_ptr, 4, 0, mouse_press, fract);
//	mlx_hook(fract->win_ptr, 6, 0, mouse_move, fract);
	mlx_hook(fract->win_ptr, 17, 0, close, 0);
	mlx_loop(fract->mlx_ptr);
}

int 	choose_fractol(t_fractol *fract)
{
	if (fract->key == 'M')
	{
		fract->xmin = -2.0;
		fract->xmax = 1.0;
		fract->ymin = -1.0;
		fract->ymax	= 1.0;
	}
	return (OK);
}

int		main(void)
{
	t_fractol		*fract;
	int 			fd;
	int 			ret;

	if (!(fract = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (MEM_NOT_ALLOCATE);
	fract->key = 'M';
	fract->repeat = 30;
	fract->x = 0;
	fract->y = 0;
	fract->color = 0;
	fd = open("../kernel.cl", O_RDONLY);
	fract->program_size = 1300;
	if (!(fract->program_source = (char *)malloc(1300)))
		return (MEM_NOT_ALLOCATE);
	if (!(fract->cl = (t_cl *)ft_memalloc(sizeof(t_cl))))
		return (MEM_NOT_ALLOCATE);
	if ((ret = read(fd, fract->program_source, fract->program_size)) < 0)
		return (READ_ERROR);
	choose_fractol(fract);
	control(fract);
	close (fd);
	return (OK);
}