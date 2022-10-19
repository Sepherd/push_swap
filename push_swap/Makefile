# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 12:38:37 by arecce            #+#    #+#              #
#    Updated: 2022/10/19 18:33:33 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

LIBFT = libft/libft.a

SRCS = push_swap.c ft_checkers.c ft_move.c ft_select_sort.c \
	ft_little_big.c ft_big_sorting.c ft_cost_calc.c ft_sort_temp.c \
	ft_utils.c ft_pos_calc.c ft_save_moves.c

HEADER = push_swap.h

OBJS = $(SRCS:.c=.o)

GREEN = \033[1;32m
RED = \033[1;31m
BLU = \033[1;34m
# YEL = \033[1;33m
# WHT = \033[1;37m
EOC = \033[1;0m


${NAME}:
		@echo "$(BLU)Compiling library...$(EOC)"
		@${MAKE} -C libft
		@echo "$(GREEN)Library done.$(EOC)"

		@echo "$(BLU)Compiling push_swap...$(EOC)"
		@$(CC) $(CFLAGS) -c $(SRCS) -I$(HEADER)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
		@mkdir obj
		@mv $(OBJS) ./obj
		@echo "$(GREEN)Push_swap build completed.$(EOC)"
		
all: ${NAME}

clean:
		@echo "$(RED)Removing .o files...$(EOC)"
		@/bin/rm -f $(OBJ)
		@/bin/rm -Rf obj
		@${MAKE} -C libft clean
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(RED)Removing the latest files...$(EOC)"
		@/bin/rm -f $(NAME)
		@${MAKE} -C libft fclean
		@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re