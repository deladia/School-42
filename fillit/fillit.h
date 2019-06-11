/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:23:21 by deladia           #+#    #+#             */
/*   Updated: 2019/06/11 16:24:49 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct				s_map
{
	char					letter;
	short					x;
	short					y;
	struct s_map			*right;
	struct s_map			*left;
	struct s_map			*up;
	struct s_map			*down;
}							t_map;

typedef struct				s_list_matrix
{
	t_map					*matrix;
	struct s_list_matrix	*next;
}							t_list_matrix;

typedef struct				s_vars
{
	char					buf[22];
	char					letter;
	int						ret;
	int						ret_pre;
}							t_vars;

typedef struct				s_vars_f
{
	int						i;
	int						j;
	int						key;
	int						d_rows;
	char					letter;
}							t_vars_f;

typedef struct				s_fig
{
	char					hash;
	short					i;
	struct s_fig			*right;
	struct s_fig			*left;
	struct s_fig			*up;
	struct s_fig			*down;
}							t_fig;

typedef struct				s_list_fig
{
	t_fig					*figure;
	struct s_list_fig		*next;
	struct s_list_fig		*prev;
}							t_list_fig;

typedef struct				s_temp
{
	int						cnt_fig;
	int						flag;
}							t_temp;

typedef struct				s_struct
{
	int						side;
	t_list_fig				*list;
	t_map					*map;
	t_map					*matrix;

}							t_struct;

int							valid_1(char *buf);
int							valid_2(char *buf, int i, int j);
void						print_map(t_map **m, int cnt);
int							ft_fillmap(t_map **map, t_list_fig **list);
void						link_hash(t_fig **fig);
void						link_hash_minus(t_fig **l1, t_fig **l2);
void						link_hash_plus(t_fig **l1, t_fig **l2);
void						store_fig(t_list_fig **list,
		char *buf, char letter);
void						create_fig(t_fig **fig, int i, char letter);
void						create_map(t_map **map, int a);
t_map						*create_cell(int x, int y);
void						find(t_map **m, int x, int y);
void						create_list(t_list_fig **list, t_fig **hash);
void						add_row(t_map **m);
void						add_col(t_map **m);
void						ft_delete_fig(t_map **map, t_list_fig **list);
int							insert_fig(t_struct **str);
int							ft_sqrt_mod	(int nb);
void						insert_hash(t_map **map, t_map **matrix, int a);
void						insert_matrix_1(t_map **map, t_map **matrix, int a);
void						insert_matrix_2(t_map **map, t_map **matrix, int a);
void						push(t_list_matrix **head, t_map **matrix);
t_list_matrix				*pop(t_list_matrix **head);
void						find_matrix(t_map **matrix, int	x, int y);
int							delete_row(t_map **matrix, t_map **map,
		t_list_matrix **stack, int one);
t_map						*restore_all_in_stack(t_list_matrix **stack,
		int restore);
void						ft_delete_fig2(t_map **map, int side, char c);
int							create_matrix(t_struct **str);
int							force(t_struct **str, t_list_matrix	**stack,
		t_temp temp);
int							cnt_row_with_letter(t_map *matrix,
		char letter, int i);
void						find_row(t_map **matrix, int nbr);
void						fillmap_2(t_map **map, t_map *matrix);
int							ft_read(int fd, t_struct **str,
		t_list_matrix **stack);
void						ft_free(t_map **matrix);

#endif
