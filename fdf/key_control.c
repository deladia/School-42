/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:44:51 by deladia           #+#    #+#             */
/*   Updated: 2019/07/11 19:45:06 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press_1(int keycode, t_fdf *ptr)
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
	return (OK);
}

int		key_press(int keycode, t_fdf *ptr)
{
	ptr->arr = clear_array(ptr);
	if (keycode == 53)
		exit(0);
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
	key_press_1(keycode, ptr);
	draw_map(ptr, ptr->map);
	return (OK);
}

int		close(int param)
{
	(void)param;
	exit(0);
}
