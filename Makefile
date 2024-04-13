# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rertzer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:29:15 by rertzer           #+#    #+#              #
#    Updated: 2024/04/13 10:40:09 by rertzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
FLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a

OBJ_DIR := obj/

SOURCES = ft_print_alpha.c	\
			ft_print_num.c	\
			ft_printf.c	\
			ft_printf_utils.c	\
			parse_fs.c \
			pointoa.c	\
			uxitoa.c	\
			ft_strlen.c	\
			ft_itoa.c

INC := ft_printf.h

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJECTS) $(INC)
	ar rcs $@ $(OBJECTS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -f $(OBJECTS)
	rm -fd $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re 
