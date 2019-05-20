# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:42:44 by atourner          #+#    #+#              #
#    Updated: 2018/02/26 16:08:15 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC_PATH = srcs/

COMP_PATH = obj/

SRC_NAME = \
	mem/ft_memalloc.c\
	mem/ft_memdel.c\
	mem/ft_memset.c\
	print/ft_putchar.c\
	print/ft_convert_wchar.c\
	print/ft_putchar_fd.c\
	print/ft_itoa_base.c\
	print/ft_printf.c\
	print/ft_sort_nbr.c\
	print/ft_sort_str.c\
	print/ft_putendl.c\
	print/ft_putendl_fd.c\
	print/ft_putnbr.c\
	print/ft_putnbr_fd.c\
	print/ft_get_arg.c\
	print/ft_putstr.c\
	print/ft_convert_wstr.c\
	print/ft_putstr_fd.c\
	str/ft_strclr.c\
	str/ft_strdel.c\
	str/ft_strequ.c\
	str/ft_striter.c\
	str/ft_striteri.c\
	str/ft_strjoin.c\
	str/ft_strmap.c\
	str/ft_strmapi.c\
	str/ft_strnequ.c\
	str/ft_strnew.c\
	str/ft_strsplit.c\
	str/ft_strsplit_space.c\
	str/ft_strsub.c\
	str/ft_strtrim.c\
	mem/ft_free_ar.c\
	mem/ft_bzero.c\
	mem/ft_memcpy.c\
	mem/ft_memmove.c\
	mem/ft_memccpy.c\
	mem/ft_memchr.c\
	str/ft_skip_char.c\
	mem/ft_memcmp.c\
	str/ft_strlen.c\
	str/ft_strdup.c\
	str/ft_strcpy.c\
	str/ft_strncpy.c\
	str/ft_strcat.c\
	str/ft_strncat.c\
	str/ft_strlcat.c\
	str/ft_strchr.c\
	str/ft_strrchr.c\
	str/ft_strstr.c\
	str/ft_strnstr.c\
	str/ft_strcmp.c\
	str/ft_strncmp.c\
	convert/ft_atoi.c\
	str/ft_isalpha.c\
	str/ft_isdigit.c\
	str/ft_isalnum.c\
	str/ft_isascii.c\
	str/ft_isprint.c\
	str/ft_toupper.c\
	str/ft_tolower.c\
	lst/ft_lstnew.c\
	lst/ft_lstdelone.c\
	lst/ft_lstdel.c\
	lst/ft_lstadd.c\
	lst/ft_lstiter.c\
	lst/ft_lstmap.c\
	math/ft_power.c\
	str/ft_islower.c\
	str/ft_iswhitespace.c\
	str/ft_isupper.c\
	str/ft_strlower.c\
	str/ft_strupper.c\
	print/ft_putllnbr.c\
	str/ft_strr.c\
	print/ft_putnstr.c\
	print/ft_convert_flags.c\
	print/apply_flags_len.c\
	print/apply_flags_sharp.c\
	print/apply_flags_precision.c\
	print/apply_flags_space.c\
	print/apply_flags_sign.c\
	str/ft_checkwchar.c\
	print/ft_special_flags.c\
	print/ft_check_flags.c\
	read/get_next_line.c\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

COMP_NAME = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@gcc -o $@ -c $< -Iincludes

$(NAME) : $(COMP_NAME)
	@echo "\033[0;35mError detected in library\033[0m"
	@sleep 2
	@echo "\033[0;33mFixed\033[0m"
	@ar rc $(NAME) $(COMP_NAME)
	@ranlib $(NAME)
	@echo "\033[0;35mCompilation de la librairie finie\033[0m"

clean :
	@echo "\033[0;31mPiou piou partially erased zone\033[0m"
	@rm -f $(COMP_NAME)

fclean : clean
	@echo "\033[0;31mPiou piou sector clear\033[0m"
	@rm -f $(NAME)

re : recompil fclean all

recompil :
	@echo "\033[0;33mRecompilation de la librairie\033[0m"
