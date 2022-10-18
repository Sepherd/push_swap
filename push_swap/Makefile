# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 12:38:37 by arecce            #+#    #+#              #
#    Updated: 2022/10/18 17:43:53 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -f
LIBRARY = libft/libft.a

SRCS = push_swap.c ft_checkers.c ft_move.c ft_select_sort.c \
	ft_little_big.c ft_big_sorting.c ft_cost_calc.c ft_sort_temp.c \
	ft_utils.c ft_pos_calc.c ft_save_moves.c

OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBRARY)

lib:
	make -C ./libft

norme: all
	norminette *.*

clean:
	$(RM) $(OBJS)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re