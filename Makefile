 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sepun <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 15:14:16 by sepun             #+#    #+#              #
#    Updated: 2024/01/12 18:07:55 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = ft_printf_hex.c \
	ft_printf_pointer.c \
	ft_printf_put_nbr.c \
	ft_printf_str_char.c \
	ft_printf.c \
	ft_putnbr_unsinged.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	    ar rcs $(NAME) $(OBJ)

clean: 
	   $(RM) $(OBJ)

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
