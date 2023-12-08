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

SRC = 

OBJ = $(SRC:.c=.o)

all = $(NAME)

NAME = $(OBJ)

clean : $(RM) $(OBJ)

fclean = clean

re = fclean all
