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
# define OK 0
# define SIDE_X 1500
# define SIDE_Y 1000

typedef struct		s_coor
{
	int 			x;
	int 			y;
	int 			z;
	struct s_coor	*right;
	struct s_coor	*down;
}					t_coor;

typedef struct		s_fdf
{
	void 			*mlx_ptr;
	void 			*win_ptr;
	void			*img_ptr;
	int 			color;
	int 			*arr;
	int 			x;
	int 			y;
	double			angle;
	double			ygl;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
	int 			coef;
	t_coor			*map;
}					t_fdf;

typedef struct		s_recount
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
}					t_recount;

t_fdf	*draw_line(int x1, int y1, int x2, int y2, t_fdf *ptr);
int 	read_map(char **argv, t_coor **map);
void	print_map(t_coor *map);
void	draw_map(t_fdf *ptr, t_coor *map);
void 	rotate_iso(t_coor *map);
void	rotate_z(t_coor *map, t_fdf *fdf);

#endif
