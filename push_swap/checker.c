/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:12:32 by arecce            #+#    #+#             */
/*   Updated: 2022/10/24 19:43:44 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_init(char **av, t_stack *a, int ac)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	a->arg = malloc(sizeof(char **) * ac - 1);
	while (k < ac - 1)
	{
		a->arg[k] = ft_split(av[i], ' ');
		i++;
		k++;
	}
	a->size = checker_digit(a->arg, ac);
}

void	make_moves(t_stack *a, t_stack *b, char *moves)
{
	if (ft_strcmp(moves, "pa\n"))
		c_push(b, a);
	else if (ft_strcmp(moves, "pb\n"))
		c_push(a, b);
	else if (ft_strcmp(moves, "sa\n"))
		c_swap(a);
	else if (ft_strcmp(moves, "sb\n"))
		c_swap(b);
	else if (ft_strcmp(moves, "ra\n"))
		c_rotate(a);
	else if (ft_strcmp(moves, "rb\n"))
		c_rotate(b);
	else if (ft_strcmp(moves, "rra\n"))
		c_reverse(a);
	else if (ft_strcmp(moves, "rrb\n"))
		c_reverse(b);
	else if (ft_strcmp(moves, "ss\n"))
		c_double_move(a, b, 1);
	else if (ft_strcmp(moves, "rr\n"))
		c_double_move(a, b, 2);
	else if (ft_strcmp(moves, "rrr\n"))
		c_double_move(a, b, 3);
	else
		ko_print();
}

void	check_push_swap(t_stack *a, t_stack *b)
{
	char	*moves;

	// moves = malloc(sizeof(char) * 4);
	moves = get_next_line(0);
	while (moves != 0)
	{	
		make_moves(a, b, moves);
		moves = get_next_line(0);
	}
	if (checker_sort(a))
		write(1, "OK\n", 3);
	else
		ko_print();
	// free(moves);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		exit(0);
	checker_init(av, &a, ac);
	mem_checker(&a, &b);
	if (checker_int_check(&a, ac) && checker_dup(&a))
	{
		if (!checker_sort(&a))
			check_push_swap(&a, &b);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	checker_free(&a, &b);
	return (0);
}
