# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sepun <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 15:14:16 by sepun             #+#    #+#              #
#    Updated: 2023/12/08 15:14:18 by sepun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GCC = gcc -Wall -Werror -Wextra

RM = rm -rf

SRC = ft_printf_hex.c/
	ft_printf_pointer.c/
	ft_printf_put_nbr.c/
	ft_printf_str_char.c/
	ft_printf.c/

OBJ = $(SRC:.c=.o)

all = $(NAME)

NAME = $(OBJ)

clean : $(RM) $(OBJ)

fclean = clean

re = fclean all
