# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/07/11 19:47:20 by deladia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fdf 

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = /usr/local/lib/ 

MY_LIB = ./libft/

INCLUDES = -I /usr/local/include -I ./libft/include

SRC = main.c draw_line.c read_map.c draw_map.c help.c key_control.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MY_LIB)
	$(CC) $(CFLAGS) -L $(LIB) -lmlx -L $(MY_LIB) -lft $(INCLUDES) -framework OpenGL -framework AppKit -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(CFLAGS) $(INCLUDES)
		
clean:
	@make clean -C $(MY_LIB)
	@/bin/rm -f $(OBJ)

fclean:	clean
	@make clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(MY_LIB)
	
re:	fclean all
