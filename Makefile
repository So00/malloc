# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:42:44 by atourner          #+#    #+#              #
#    Updated: 2019/03/21 10:18:29 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CFLAGS = -Wall -Werror -Wextra -fPIC

SRC_PATH = src/

H = includes

SRC = \
		main.c\

SRC = $(addprefix $(SRC_PATH), $(SRC))

COMP_NAME = $(SRC:.c=.o)

LIB_PATH = ft_printf

all : LIB $(NAME)

LIB:
	@make -C $(LIB_PATH)

%.o : %.c $(H) $(LIB_PATH)/libftprintf.a
	@gcc -shared -o $@ $(CFLAGS) -c $< -I$(LIB_PATH)/$(H) -I$(H)

$(NAME) : $(COMP_NAME) Makefile
	@gcc  $(CFLAGS) $(NAME) $(COMP_NAME)
	@echo "\n\033[0;35mCompilation de la librairie finie\033[0m"

clean :
	@echo "\033[0;31mPiou piou partially erased zone\033[0m"
	@rm -f $(COMP_NAME)
	@make clean -C $(LIB_PATH)

fclean : clean
	@echo "\033[0;31mPiou piou sector clear\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re : recompil fclean all

recompil :
	@echo "\033[0;33mRecompilation de l'assembleur\033[0m"
