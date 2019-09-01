# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/09/01 19:55:48 by deladia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fractol 

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = /usr/local/lib/ 

MY_LIB = ./libft/

INCLUDES = -I /usr/local/include -I ./libft/include

SRC = main.c create_cl.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MY_LIB)
	$(CC) $(CFLAGS) -L $(LIB) -lmlx -L $(MY_LIB) -lft $(INCLUDES) -framework OpenGL -framework AppKit -framework OpenCL -o $@ $^

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
