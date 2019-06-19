#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>

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

t_ptr	*draw_line(int x1, int y1, int x2, int y2, t_ptr *ptr);

#endif
