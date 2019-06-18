#include <nameser.h>
#include "fdf.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int 	*clear_array(t_ptr *ptr)
{
	int 	i;

	i = 0;
	while(i <= (ptr->side_x * ptr->side_y))
	{
		ptr->arr[i] = 0x000000;
		i++;
	}
	return (ptr->arr);
}

int		key_press(int keycode, t_ptr *ptr)
{
	if (keycode == 0 && ptr->x > 0)
		ptr->arr[(--ptr->x) + (ptr->y * ptr->side_x)] = 0xFFFFFF;
	if (keycode == 1 && (ptr->y < (ptr->side_y - 1)))
		ptr->arr[ptr->x + (++ptr->y * ptr->side_x)] = 0xFFFFFF;
	if (keycode == 2 && (ptr->x < (ptr->side_x - 1)))
		ptr->arr[(++ptr->x) + (ptr->y * ptr->side_x)] = 0xFFFFFF;
	if (keycode == 13 && ptr->y > 0)
		ptr->arr[ptr->x + (--ptr->y * ptr->side_x)] = 0xFFFFFF;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	ptr->arr = clear_array(ptr);
	return (0);
}

int 	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_ptr	*ptr;
	int 	bit_per_pixel;
	int 	size_line;
	int 	endian;

	ptr = (t_ptr *)malloc(sizeof(t_ptr));
	ptr->x = 0;
	ptr->y = 0;
	ptr->side_x = 500;
	ptr->side_y = 500;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, ptr->side_x, ptr->side_y, "mlx 42");
	ptr->mlx_ptr = mlx_ptr;
	ptr->win_ptr = win_ptr;
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, ptr->side_x, ptr->side_y);
	ptr->arr = (int *) mlx_get_data_addr(ptr->img_ptr, &bit_per_pixel, &size_line, &endian);
	//mlx_hook(win_ptr, 2, 0, key_press, ptr); //press key
	draw_line(10, 10, 400, 40, ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
