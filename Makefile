# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 12:39:17 by thinguye          #+#    #+#              #
#    Updated: 2019/12/11 16:53:43 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HDR = hdrs.h
SRC = main.c ft_check_tetri.c ft_tetri_to_list.c \
		ft_generate_map.c set_coords.c smallest_square.c \
		str_to_binary.c

LIB = libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -I $(HDR) $(LIB) -o $(NAME)

clean: 
	rm -rf *.swp

fclean: clean
	rm -rf $(NAME)

re: fclean all
