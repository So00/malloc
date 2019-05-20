# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <atourner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:42:41 by atourner          #+#    #+#              #
#    Updated: 2019/03/25 11:13:43 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = stdlib.so

COMPILE = gcc

FLAGS= -Wall -Werror -Wextra

SRC = 	stdlib.c\
		free.c\
		malloc.c\
		realloc.c\
		initialize.c

CMP = $(SRC:.c=.o)

LIBPRINTF = ft_printf/libftprintf.a

.PHONY:    all clean fclean re

all : NAME

NAME : PRINTF $(CMP)
	$(COMPILE) -shared -o $(NAME) $(SRC) $(LIBPRINTF)

PRINTF:
	make -C ft_printf

%.o: %.cpp
	$(COMPILE) -c $< -o $@

clean :
	make clean -C ft_printf
	rm -rf $(CMP)

fclean : clean
	make fclean -C ft_printf
	rm -rf $(NAME) test

re : fclean all

test: all
	gcc main.c $(LIBPRINTF) stdlib.so -o test && ./test