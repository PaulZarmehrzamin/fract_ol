# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 10:06:16 by pzarmehr          #+#    #+#              #
#    Updated: 2017/03/16 19:36:02 by pzarmehr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_SRC = ./sources/
PATH_INC = ./includes/
PATH_LIB = ./libft/includes/

LFT = -L ./libft/ -lft
MLX = -lmlx -framework OpenGL -framework AppKit
MATH = -lm

SRC = main.c \
	  img.c \
	  color.c \
	  julia.c \
	  mandelbrot.c \
	  tricorn.c \
	  burningship.c \
	  tree.c \
	  koch.c \
	  square.c \
	  cross.c \
	  cmd.c \
	  hook.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFT) $(MLX) $(MATH)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^ -I $(PATH_INC) -I $(PATH_LIB)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean:
	make -C libft fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
