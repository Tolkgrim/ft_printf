# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 15:14:18 by jdutschk          #+#    #+#              #
#    Updated: 2022/03/22 16:03:01 by jdutschk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc 
RM = rm -f
CONVERT = -c -o
NOR = norminette

FILE = ft_print_ptr ft_printf_hex ft_printf_nbr ft_printf_str ft_printf \

DIRECTORY = ./src/

SRC = $(addprefix $(DIRECTORY), $(addsuffix .c, $(FILE)))
OBJ = $(addprefix $(DIRECTORY), $(addsuffix .o, $(FILE)))

%.o : %.c 
	$(CC) $(FLAGS) $(CONVERT) $@ $<

$(NAME): $(OBJ)
	@$(AR) $@ $^

all : $(NAME)

go :
	$(CC) $(FLAGS) $(NAME) main.c
	./a.out

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

alln : all
	$(NOR)
re : clean all 

ar = all clean

.PHONY: all clean fclean re ar