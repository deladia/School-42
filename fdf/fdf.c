//#include <nameser.h>
#include "fdf.h"

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

t_coor		*recount(t_coor *draw, t_coor *wall, t_ptr *ptr)
{
	draw->x = (wall->x - ptr->x) * cos(ptr->angle) - (wall->y - ptr->y) * sin(ptr->angle);
	draw->y = (wall->x - ptr->x) * sin(ptr->angle) + (wall->y - ptr->y) * cos(ptr->angle);
	return(draw);
}

int		key_press(int keycode, t_ptr *ptr)
{
	double	x1;
	double 	x2;
	double 	y1;
	double 	y2;
	t_coor	*wall1;
	t_coor	*wall2;
	t_coor	*wall3;
	t_coor	*wall4;
	t_coor	*draw1;
	t_coor	*draw2;
	double	h;
	double 	w;
	double x11;
	double x12;
	double y11;
	double y12;
	double x21;
	double x22;
	double y21;
	double y22;


	wall1 = (t_coor *)ft_memalloc(sizeof(t_coor));
	wall2 = (t_coor *)ft_memalloc(sizeof(t_coor));
	wall3 = (t_coor *)ft_memalloc(sizeof(t_coor));
	wall4 = (t_coor *)ft_memalloc(sizeof(t_coor));
	draw1 = (t_coor *)ft_memalloc(sizeof(t_coor));
	draw2 = (t_coor *)ft_memalloc(sizeof(t_coor));

	wall1->x = 3;
	wall1->y = 8;

	wall2->x = 7;
	wall2->y = 9;


//	if (keycode == 0 && ptr->x > 0)
//		ptr->arr[(--ptr->x) + (ptr->y * ptr->side_x)] = 0x000000;
//	if (keycode == 1 && (ptr->y < (ptr->side_y - 1)))
//		ptr->arr[ptr->x + (++ptr->y * ptr->side_x)] = 0x000000;
//	if (keycode == 2 && (ptr->x < (ptr->side_x - 1)))
//		ptr->arr[(++ptr->x) + (ptr->y * ptr->side_x)] = 0x000000;
//	if (keycode == 13 && ptr->y > 0)
//		ptr->arr[ptr->x + (--ptr->y * ptr->side_x)] = 0x000000;
	if (keycode == 0)
		--ptr->x;
	if (keycode == 1)
		--ptr->y;
	if (keycode == 2)
		++ptr->x;
	if (keycode == 13)
		++ptr->y;
	if (keycode == 12)
		ptr->angle += 0.03;
	if (keycode == 14)
		ptr->angle -= 0.03;




	x1 = (wall1->x - ptr->x) * cos(ptr->angle) - (wall1->y - ptr->y) * sin(ptr->angle);
	y1 = (wall1->x - ptr->x) * sin(ptr->angle) + (wall1->y - ptr->y) * cos(ptr->angle);

	h = 500 / y1;
	w = x1 / y1 * 1000 / 2;

	x11 = w + 1000 / 2;
	y11 = 1000 / 2 + h / 2;

	x12 = w + 1000 / 2;
	y12 = 1000 / 2 - h / 2;

	draw_line((int)x11, (int)y11, (int)x12, (int)y12, ptr);


	x2 = (wall2->x - ptr->x) * cos(ptr->angle) - (wall2->y - ptr->y) * sin(ptr->angle);
	y2 = (wall2->x - ptr->x) * sin(ptr->angle) + (wall2->y - ptr->y) * cos(ptr->angle);

	h = 500 / y2;
	w = x2 / y2 * 1000 / 2;

	x21 = w + 1000 / 2;
	y21 = 1000 / 2 + h / 2;

	x22 = w + 1000 / 2;
	y22 = 1000 / 2 - h / 2;

	draw_line((int)x21, (int)y21, (int)x22, (int)y22, ptr);
	draw_line((int)x12, (int)y12, (int)x22, (int)y22, ptr);
	draw_line((int)x21, (int)y21, (int)x11, (int)y11, ptr);


	ptr->arr[500 + 500 * ptr->side_x] = 0xFF0000;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	ptr->arr = clear_array(ptr);
	return (0);
}

//int 	press_key(int keycode, t_ptr *ptr)
//{
//
//}

int 	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_ptr	*ptr;
	int 	bit_per_pixel;
	int 	size_line;
	int 	endian;
	t_arr 	*array;
	t_coor	*map;

	array = (t_arr *)ft_memalloc(sizeof(t_arr));
	map = NULL;
	if (argc == 2)
		read_map(argv, &map);
	print_map(map);



	ptr = (t_ptr *)malloc(sizeof(t_ptr));
	ptr->x = 5;
	ptr->y = 5;
	ptr->side_x = 1000;
	ptr->side_y = 1000;
	ptr->angle = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, ptr->side_x, ptr->side_y, "mlx 42");
	ptr->mlx_ptr = mlx_ptr;
	ptr->win_ptr = win_ptr;
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, ptr->side_x, ptr->side_y);
	ptr->arr = (int *) mlx_get_data_addr(ptr->img_ptr, &bit_per_pixel, &size_line, &endian);

//	draw_map(ptr, map);
//	mlx_hook(win_ptr, 2, 0, press_key, ptr);

	mlx_hook(win_ptr, 2, 0, key_press, ptr); //press key
//	draw_line(200, 100, 300, 100, ptr);
//	draw_line(300, 100, 300, 300, ptr);
//	draw_line(200, 100, 200, 300, ptr);
//	draw_line(200, 175, 300, 175, ptr);
//	draw_line(200, 100, 300, 100, ptr);
//	draw_line(150, 300, 350, 300, ptr);
//	draw_line(150, 375, 350, 375, ptr);
//	draw_line(150, 300, 150, 375, ptr);
//	draw_line(350, 300, 350, 375, ptr);
//	draw_line(250, 300, 250, 375, ptr);

	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

// сделать дефайн чтобы не такскать структуру
//& and && первое сначала проверяет все, а второе при первом фолсе дропается
