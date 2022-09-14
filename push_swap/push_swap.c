/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:43 by arecce            #+#    #+#             */
/*   Updated: 2022/09/14 17:35:00 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_swap(struct s_stack array)
{
	while (!check_sorting(array))
	{
		if (array.stack[0] > array.stack[1])
			rotate(array, "ra\n");
		else
		{
			swap(array, "sa\n");
			rotate(array, "ra\n");
		}
	}
}

int	main(int ac, char **av)
{
	struct s_stack	stack_a;
	struct s_stack	stack_b;

	if (ac == 1)
		exit(0);
	stack_a.size = ac - 1;
	stack_b.size = 0;
	stack_a.stack = malloc(sizeof(int) * stack_a.size);
	stack_b.stack = malloc(sizeof(int) * (ac - 1));
	if (!stack_a.stack)
		exit(0);
	if ((ac > 1) && check_isdigit(av) && check_int(av, stack_a)
		&& check_duplicate(stack_a) && !check_sorting(stack_a))
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
			push_swap(stack_a);
			print_stack(stack_a);
		}
	}
	else if (check_sorting(stack_a))
		print_stack(stack_a);
	else
		ft_printf("Error\n");
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}
