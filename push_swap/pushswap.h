/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:38:47 by arecce            #+#    #+#             */
/*   Updated: 2022/09/20 18:16:40 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	pos_min;
	int	pos_max;
	int	mosse;
}				t_stack;

int		check_isdigit(char **str);
int		check_int(char **str, t_stack *array);
int		check_duplicate(t_stack *array);
int		check_sorting(t_stack *array);
int		find_bigger(t_stack *array);
int		find_little(t_stack *array);
void	push_bigger(t_stack *array_a, t_stack *array_b);
void	push_little(t_stack *array_a, t_stack *array_b);
void	swap(t_stack *array, char *move);
void	rotate(t_stack *array, char *move);
void	print_stack(t_stack *array);
void	reverse(t_stack *array, char *move);
void	double_move(t_stack *first, t_stack *second, int move);
void	push(t_stack *pusher, t_stack *pushed, char *move);
int		find_min(t_stack *array);
void	mini_sort(t_stack *array_a, t_stack *array_b);
void	sort_three(t_stack *array);
void	sort_five(t_stack *array_a, t_stack *array_b);
void	sort_hundred(t_stack *array_a, t_stack *array_b);
/* void	sort_hundred(t_stack *array_a, t_stack *array_b); */

#endif