# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/06/18 16:25:01 by deladia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fdf 

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = /usr/local/lib/ 

INCLUDES = -I /usr/local/include

SRC = fdf.c draw_line_x.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L $(LIB) -lmlx $(INCLUDES) -framework OpenGL -framework AppKit -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(CFLAGS) $(INCLUDES)
		
clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	@make clean
	@/bin/rm -f $(NAME)
	
re:	fclean all
