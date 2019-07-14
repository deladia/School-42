/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:38:11 by deladia           #+#    #+#             */
/*   Updated: 2019/07/10 18:38:13 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# define MEMORY_NOT_ALLOCATE 1
# define CANT_OPEN_FILE 2
# define OK 0
# define SIDE_X 1500
# define SIDE_Y 1000

typedef struct		s_coor
{
	int				x;
	int				y;
	int				z;
	struct s_coor	*right;
	struct s_coor	*down;
}					t_coor;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				color;
	int				*arr;
	int				x;
	int				y;
	double			angle;
	double			ygl;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
	int				coef;
	int				flag;
	t_coor			*map;
	int				mouse_x;
	int				mouse_y;
}					t_fdf;

typedef struct		s_param
{
	int				dx;
	int				dy;
	double			gradient;
	double			xend;
	double			yend;
	double			xgap;
	double			ygap;
	int				xpxl1;
	int				ypxl1;
	double			intery;
	int				xpxl2;
	int				ypxl2;
}					t_param;

typedef struct		s_rec
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
}					t_rec;

t_fdf				*draw_line(t_rec *rec, t_fdf *ptr);
int					read_map(char **argv, t_coor **map);
void				draw_map(t_fdf *ptr, t_coor *map);
int					*clear_array(t_fdf *ptr);
void				ft_swap_fdf(t_rec *r, t_param *p);
double				fpart(double x);
void				ft_swap(double *a, double *b);
int					ft_round(double x);
int					ipart(double x);
int					key_press(int keycode, t_fdf *ptr);
int					close(int param);

#endif
