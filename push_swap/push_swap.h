/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:38:47 by arecce            #+#    #+#             */
/*   Updated: 2022/10/19 17:29:26 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# include "libft/libft.h"

typedef struct s_stack
{
	int		*stack;
	int		size;
	int		pos_min;
	int		pos_max;
	int		value;
	int		index;
	int		pos;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	int		mosse;
	char	***arg;
}				t_stack;

void	memory_manage(t_stack *arr_a, t_stack *arr_b, t_stack *ta, t_stack *tb);
void	free_arg(t_stack *a, int ac);
void	free_manage(t_stack *arr_a, t_stack *arr_b, \
					t_stack *arr_c, t_stack *arr_d);
int		check_util(char ***str, int i);
int		check_isdigit(char ***str, int ac);
void	copy_int(t_stack *a, t_stack *tb, int i, long long temp);
int		check_int(t_stack *a, t_stack *tb, int ac);
int		check_dup(t_stack *array);
int		check_sort(t_stack *array);
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
void	select_sort(t_stack *sa, t_stack *sb, t_stack *ta, t_stack *tb);
void	sort_three(t_stack *array);
void	sort_five(t_stack *array_a, t_stack *array_b);
void	sort_easy(t_stack *ta, t_stack *tb);
void	push_bigger_easy(t_stack *ta, t_stack *tb);
void	push_easy(t_stack *tb, t_stack *ta);
void	get_index(t_stack *arr, t_stack *temp);
void	target_index_helper(t_stack *a);
void	get_target_index(t_stack *arr, t_stack *arr_b, t_stack *temp);
void	get_pos(t_stack *arr);
void	get_big_pos(t_stack *arr_a, t_stack *arr_b);
void	get_all_pos(t_stack *arr_a, t_stack *arr_b, t_stack *temp);
void	make_positive(int nb_a, int nb_b);
void	cost_b_calc(t_stack *arr);
void	cost_a_calc(t_stack *arr, t_stack *arr_b);
void	cheap_cost(t_stack *arr_a, t_stack *arr_b, t_stack *temp);
void	big_sort(t_stack *a, t_stack *b, t_stack *t);
void	rot_or_rev_a(t_stack *a, t_stack *b);
void	rot_or_rev_b(t_stack *b);
void	little_move(t_stack *a);
void	empty_b_stack(t_stack *a, t_stack *b);
void	save_move(t_stack *a, t_stack *b);
void	move_bigger(t_stack *a, t_stack *b);
void	error_call(void);

#endif