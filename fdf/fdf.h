#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

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
}					t_coor;

t_ptr	*draw_line(int x1, int y1, int x2, int y2, t_ptr *ptr);
t_arr 	*read_file(char **argv, t_arr *array);
t_ptr	*draw_map(t_ptr *ptr, t_arr *array);

#endif
