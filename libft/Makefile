# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 16:13:50 by pzarmehr          #+#    #+#              #
#    Updated: 2017/01/12 16:17:49 by pzarmehr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_SRC = ./
PATH_INC = ./includes/

SRC = ft_isupper.c \
	  ft_islower.c \
  	  ft_isalpha.c \
  	  ft_isdigit.c \
  	  ft_isalnum.c \
  	  ft_isspace.c \
  	  ft_isascii.c \
  	  ft_isprint.c \
  	  ft_toupper.c \
  	  ft_tolower.c \
  	  ft_putchar.c \
  	  ft_putstr.c \
  	  ft_putnbr.c \
  	  ft_error.c \
  	  ft_putchar_fd.c \
  	  ft_putstr_fd.c \
  	  ft_putnbr_fd.c \
  	  ft_error_fd.c \
  	  ft_atoi.c \
  	  ft_itoa.c \
  	  ft_strlen.c \
  	  ft_strcpy.c \
  	  ft_strncpy.c \
  	  ft_strdup.c \
  	  ft_strchr.c \
  	  ft_strrchr.c \
  	  ft_strstr.c \
  	  ft_strnstr.c \
  	  ft_strcmp.c \
  	  ft_strncmp.c \
  	  ft_strequ.c \
  	  ft_strnequ.c \
  	  ft_strsub.c \
  	  ft_strjoin.c \
	  get_next_line.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^ -I $(PATH_INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
