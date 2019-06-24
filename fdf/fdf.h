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

typedef struct		s_ptr
{
	void 			*mlx_ptr;
	void 			*win_ptr;
	void			*img_ptr;
	int 			*arr;
	int 			x;
	int 			y;
	int 			side_x;
	int 			side_y;
	double			angle;
}					t_ptr;

typedef struct		s_arr
{
	int 			**arr;
	int 			cnt_row;
	int 			cnt_col;
}					t_arr;

typedef struct		s_coor
{
	int 			x;
	int 			y;
	int 			z;
	struct s_coor	*right;
	struct s_coor	*down;
}					t_coor;

t_ptr	*draw_line(int x1, int y1, int x2, int y2, t_ptr *ptr);
int 	read_map(char **argv, t_coor **map);
void	print_map(t_coor *map);
void	draw_map(t_ptr *ptr, t_coor *map);

#endif
