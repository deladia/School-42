/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:24:15 by deladia           #+#    #+#             */
/*   Updated: 2019/06/11 16:43:16 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_mod(int nbr)
{
	int	i;

	i = 1;
	while (i * i < nbr)
		i++;
	return (i);
}

void	create_list(t_list_fig **list, t_fig **hash)
{
	if (!hash)
	{
		if (!(*list = (t_list_fig *)ft_memalloc(sizeof(t_list_fig))))
			return ;
	}
	else
	{
		if (!(*list)->figure)
			(*list)->figure = *hash;
		else
		{
			(*list)->next = (t_list_fig *)ft_memalloc(sizeof(t_list_fig));
			(*list)->next->figure = *hash;
			(*list)->next->prev = *list;
			(*list) = (*list)->next;
		}
	}
}

int		ft_read(int fd, t_struct **str, t_list_matrix **stack)
{
	t_vars			v;
	t_temp			temp;

	v.letter = 'A';
	temp.cnt_fig = 0;
	temp.flag = 0;
	while ((v.ret = read(fd, v.buf, 21)) >= 20)
	{
		v.buf[v.ret] = '\0';
		if (valid_1(v.buf) == -1 || valid_2(v.buf, v.ret, temp.flag) == -1)
			return (-1);
		v.ret_pre = v.ret;
		store_fig(&(*str)->list, v.buf, v.letter);
		if (temp.cnt_fig++ >= 26)
			return (-1);
		v.letter++;
	}
	if (v.ret != 0 || v.ret_pre != 20)
		return (-1);
	(*str)->side = ft_sqrt_mod(4 * temp.cnt_fig);
	create_map(&(*str)->map, (*str)->side);
	(*str)->side = create_matrix(str);
	force(str, stack, temp);
	print_map(&(*str)->map, (*str)->side);
	exit(0);
}

int		main(int argc, char **argv)
{
	int				fd;
	t_struct		*str;
	t_list_matrix	*stack;

	str = (t_struct *)ft_memalloc(sizeof(t_struct));
	create_list(&str->list, NULL);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (-1);
		if (ft_read(fd, &str, &stack) < 0)
		{
			ft_putstr("error\n");
			return (-1);
		}
	}
	else
		ft_putstr("usage: ./fillit sample_file\n");
	return (0);
}
