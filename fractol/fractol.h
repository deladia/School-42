#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# define SIDE_Y 1000
# define SIDE_X 1500

typedef struct		s_fractol
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
}					t_fractol;

#endif
