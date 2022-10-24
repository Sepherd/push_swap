# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 12:38:37 by arecce            #+#    #+#              #
#    Updated: 2022/10/24 19:29:50 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

SRCS = push_swap.c ft_checkers.c ft_move.c ft_select_sort.c \
	ft_little_big.c ft_big_sorting.c ft_cost_calc.c ft_sort_temp.c \
	ft_utils.c ft_pos_calc.c ft_save_moves.c

B_SRCS = checker.c checker_utils.c checker_move.c check_checker.c get_next_line.c \
		get_next_line_utils.c

HEADER = push_swap.h
B_HEADER = checker.h

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

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

bonus: all $(B_OBJS)
		@echo "$(BLU)Compiling bonus...$(EOC)"
		@$(CC) $(CFLAGS) -c $(B_SRCS) -I$(B_HEADER)
		@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(B_OBJS) $(LIBFT)
		@mkdir b_obj
		@mv $(B_OBJS) ./b_obj
		@echo "$(GREEN)Bonus build completed.$(EOC)"

clean:
		@echo "$(RED)Removing .o files...$(EOC)"
		@/bin/rm -f $(OBJ) $(B_OBJS)
		@/bin/rm -Rf obj
		@/bin/rm -Rf b_obj
		@${MAKE} -C libft clean
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(RED)Removing the latest files...$(EOC)"
		@/bin/rm -f $(NAME) $(NAME_BONUS)
		@${MAKE} -C libft fclean
		@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re