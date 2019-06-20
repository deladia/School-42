#include "fdf.h"

t_arr 	*int_split(char *str, t_arr *array)
{
	int 	i;
	int 	j;

	array->cnt_col = 0;
	array->cnt_row = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			array->cnt_row++;
		if (str[j] == ' ' && array->cnt_row == 0 && str[j + 1] && str[j + 1] != ' ')
			array->cnt_col++;
		j++;
	}
	array->cnt_col++;
	printf("%d  %d \n", array->cnt_row, array->cnt_col);
	array->arr = (int **)ft_memalloc(sizeof(int *) * (array->cnt_row));
	i = 0;
	while(i < array->cnt_row)
	{
		array->arr[i] = (int *)ft_memalloc(sizeof(int) * (array->cnt_col));
		i++;
	}
	i = 0;
	j = 0;
	while (*str != '\0')
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')  //подумать над отрицательным z
		{
			array->arr[i][j] = ft_atoi(str);          //не работает подубажить
			j++;
			while (*(str + 1) >= '0' && *(str + 1) <= '9')
				str++;
		}
		else if (*str == '\n')
		{
			i++;
			j = 0;
		}
		str++;
	}
	i = 0;
	while (i < array->cnt_row)
	{
		j = 0;
		while (j < array->cnt_col)
		{
			printf("%2d  ", array->arr[i][j]);
			j++;
		}
		printf("%c", '\n');
		i++;
	}
	return(array);
}

t_arr 	*read_file(char **argv, t_arr *array)
{
	int 	fd;
	char	*tmp;
	char	*store;
	char 	buf[11];
	int 	ret;

	fd = open(argv[1], O_RDONLY);
	tmp = NULL;
	store = NULL;
	while((ret = read(fd, buf, 10)) > 0)
	{
		buf[ret] = '\0';
		if (!store)
			store = ft_strdup(buf);
		else
		{
			tmp = store;
			store = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = NULL;
		}
	}
	printf("%s\n\n", store);
	array = int_split(store, array); //надо потестить
	return (array);
}