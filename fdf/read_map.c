#include "fdf.h"

int		create_row_2(t_coor **row, char *line, int j, int y)
{
	int		i;
	t_coor	*ptr;

	ptr = *row;
	i = 0;
	while (line[j] != '\0')
	{
		if ((line[j] >= '0' && line[j] <= '9') || line[j] == '-')
		{
			i++;
			if (!(ptr->right = (t_coor *)ft_memalloc(sizeof(t_coor))))
				return (MEMORY_NOT_ALLOCATE);
			ptr = ptr->right;
			ptr->x = i;
			ptr->y = y;
			ptr->z = ft_atoi((line + j));
			while (line[j + 1] >= '0' && line[j + 1] <= '9')
				j++;
		}
		j++;
	}
	return (OK);
}

int		create_row(char *line, int y, t_coor **row)
{
	int		j;

	if (!((*row) = (t_coor *)ft_memalloc(sizeof(t_coor))))
		return (MEMORY_NOT_ALLOCATE);
	(*row)->x = 0;
	(*row)->y = y;
	(*row)->z = ft_atoi(line);
	j = 0;
	while (line[j + 1] >= '0' && line[j + 1] <= '9')
		j++;
	if (create_row_2(row, line, j, y) == MEMORY_NOT_ALLOCATE)
		return (MEMORY_NOT_ALLOCATE);
	return (OK);
}

void	connect_link(t_coor **map, t_coor **row)
{
	t_coor	*ptr;

	ptr = *map;
	while (ptr->down)
		ptr = ptr->down;
	while (ptr)
	{
		ptr->down = (*row);
		if (!(ptr->right) || !((*row)->right))
			break ;
		ptr = ptr->right;
		(*row) = (*row)->right;
	}
}

int		read_map(char **argv, t_coor **map)
{
	int		fd;
	int		y;
	char	*line;
	t_coor	*row;

	y = 0;
	row = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (row == NULL)
		{
			create_row(line, y, &row);
			(*map) = row;
		}
		else
		{
			create_row(line, y, &row);
			connect_link(map, &row);
		}
		free(line);
		line = NULL;
		y++;
	}
	return (OK);
}

void	print_map(t_coor *map)
{
	t_coor	*x;
	t_coor	*y;

	y = map;
	while (y)
	{
		x = y;
		while (x)
		{
			printf("%2d ", x->z);
			if (!(x->right))
				break ;
			x = x->right;
		}
		printf("\n");
		if (!(y->down))
			break ;
		y = y->down;
	}
}
