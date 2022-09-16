# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 17:02:51 by anastacia         #+#    #+#              #
#    Updated: 2022/09/16 17:04:38 by anastacia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = push_swap
SRC = push_swap src/list src/check_args\
	src/operations\

PRINTF = printf/libftprintf.a
PRINTF_PATH = ./printf

LIBFT = libft/libft.a
LIBFT_PATH = ./libft


CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -fsanitize=address



all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(SRC:=.o)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

clean:
	$(RM) $(NAME) $(SRC:=.o)

fclean: clean
	$(RM) $(LIBFT) $(PRINTF)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re