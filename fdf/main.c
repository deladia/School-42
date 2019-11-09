/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:03:03 by deladia           #+#    #+#             */
/*   Updated: 2019/10/08 01:52:18 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_move(int x, int y, t_fdf *ptr)
{
	ptr->arr = clear_array(ptr);
	if (ptr->flag == 1)
	{
		ptr->x -= ptr->mouse_x - x;
		ptr->y -= (ptr->mouse_y - y);
		ptr->mouse_x = x;
		ptr->mouse_y = y;
	}
	draw_map(ptr, ptr->map);
	return (OK);
}

int		mouse_press(int button, int x, int y, t_fdf *ptr)
{
	ptr->arr = clear_array(ptr);
	if (button == 4)
		ptr->coef += 1;
	if (button == 5 && ptr->coef != 0)
		ptr->coef -= 1;
	if (button == 1)
	{
		ptr->flag *= -1;
		ptr->mouse_x = x;
		ptr->mouse_y = y;
	}
	draw_map(ptr, ptr->map);
	return (OK);
}

void	control(t_fdf *fdf, t_coor *map)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, SIDE_X, SIDE_Y, "window");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, SIDE_X, SIDE_Y);
	fdf->arr = (int *)mlx_get_data_addr(fdf->img_ptr,
			&fdf->bit_per_pixel, &fdf->size_line, &fdf->endian);
	fdf->x = SIDE_X / 2;
	fdf->y = SIDE_Y / 2;
	fdf->coef = 8;
	fdf->ygl = 0;
	draw_map(fdf, map);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close, 0);
	mlx_loop(fdf->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
			return (MEMORY_NOT_ALLOCATE);
		fdf->map = NULL;
		fdf->angle = 0.523599;
		fdf->color = 0xFC0FC0;
		fdf->flag = -1;
		if (read_map(argv, &fdf->map) == CANT_OPEN_FILE)
		{
			ft_putstr("File not found\n");
			exit(0);
		}
		control(fdf, fdf->map);
	}
	else
		ft_putstr("usage: ./fdf sample_file\n");
	return (OK);
}
