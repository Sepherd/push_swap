# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 12:38:37 by arecce            #+#    #+#              #
#    Updated: 2022/09/13 16:43:52 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -f
LIBRARY = libft/libft.a

SRCS = push_swap.c ft_utils.c ft_move.c

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