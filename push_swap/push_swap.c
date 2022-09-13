/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:43 by arecce            #+#    #+#             */
/*   Updated: 2022/09/13 19:39:29 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	struct s_stack	stack_a;
	struct s_stack	stack_b;

	if (ac == 1)
		exit(0);
	stack_a.stack = malloc(sizeof(int) * (ac - 1));
	stack_b.stack = malloc(sizeof(int) * (ac - 1));
	if (!stack_a.stack)
		exit(0);
	stack_a.size = ac - 1;
	stack_b.size = ac - 1;
	/* if (check_isdigit(av))
		ft_printf("sono numeri\n");
	if (check_int(av, stack_a))
		ft_printf("sono interi\n");
	if (check_duplicate(stack_a))
		ft_printf("no doppioni\n"); */
	if (check_isdigit(av) && check_int(av, stack_a) && check_duplicate(stack_a) && check_int(av, stack_b) && check_duplicate(stack_b))
	{
		if (ac == 2)
			ft_printf("%d\n", stack_a.stack[0]);
		if (ac == 3 && stack_a.stack[0] > stack_a.stack[1])
		{
			swap(stack_a, "sa\n");
			print_stack(stack_a);
		}
		else
		{
			double_move(stack_a, stack_b, 2);
			print_stack(stack_a);
		}
	}
	else
		ft_printf("Error\n");
	free(stack_a.stack);
	return (0);
}
