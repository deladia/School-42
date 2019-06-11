# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/06/11 16:27:31 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB_FOLDER = libft

LIB = ./$(LIB_FOLDER)

INCLUDES = -I./$(LIB_FOLDER)

SRC = fillit.c create_map.c fillmap.c print_map.c validation.c link_hash.c store_fig.c ft_free.c\
	expand_map.c insert_fig.c fillmap2.c force.c delete_row.c stack.c ft_delete_fig.c insert_matrix.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_FOLDER)
	$(CC) $(CFLAGS) -L $(LIB) -lft $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(CFLAGS) $(INCLUDES)
		
clean:
	@make clean -C $(LIB_FOLDER)
	@/bin/rm -f $(OBJ)

fclean:	clean
	@make clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_FOLDER)

re:	fclean all
