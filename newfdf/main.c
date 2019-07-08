#include "fdf.h"

int 	*clear_array(t_fdf *ptr)
{
	int		i;

	i = 0;
	while(i <= (SIDE_X * SIDE_Y))
	{
		ptr->arr[i] = 0x000000;
		i++;
	}
	return (ptr->arr);
}

int		key_press(int keycode, t_fdf *ptr)
{
	ptr->arr = clear_array(ptr);
	if (keycode == 53)
		exit (0);
	if (keycode == 0)
		ptr->x -= 10;
	if (keycode == 1)
		ptr->y += 10;
	if (keycode == 2)
		ptr->x += 10;
	if (keycode == 13)
		ptr->y -= 10;
	if (keycode == 12)
		ptr->angle += 0.03;
	if (keycode == 14)
		ptr->angle -= 0.03;
	if (keycode == 69)
		ptr->coef += 1;
	if (keycode == 78 && ptr->coef != 0)
		ptr->coef -= 1;
	if (keycode == 34)
	{
		ptr->angle = 0.523599;
		ptr->ygl = 0;
	}
	if (keycode == 6)
		ptr->ygl += 0.03;
	if (keycode == 7)
		ptr->ygl -= 0.03;
	draw_map(ptr, ptr->map);
	return (0);
}

void	control(t_fdf *fdf, t_coor *map)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, SIDE_X, SIDE_Y, "window");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, SIDE_X, SIDE_Y);
	fdf->arr = (int *) mlx_get_data_addr(fdf->img_ptr, &fdf->bit_per_pixel, &fdf->size_line, &fdf->endian);
	fdf->x = SIDE_X / 2;
	fdf->y = SIDE_Y / 2;
	fdf->coef = 8;
	fdf->ygl = 0;
	draw_map(fdf, map);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
			return (MEMORY_NOT_ALLOCATE);
		fdf->map = NULL;
		read_map(argv, &fdf->map);
		fdf->angle = 0.523599;
		control(fdf, fdf->map);
	}
	else
		ft_putstr("usage: ./fdf sample_file\n");
	return 0;
} //добавить еррор при не существующем файле