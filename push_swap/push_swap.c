/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:43 by arecce            #+#    #+#             */
/*   Updated: 2022/09/20 18:12:37 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1 || ac == 2)
		exit(0);
	stack_a.size = ac - 1;
	stack_b.size = 0;
	stack_a.stack = (int *)malloc(sizeof(int) * stack_a.size);
	stack_b.stack = (int *)malloc(sizeof(int) * (ac - 1));
	if (!stack_a.stack || !stack_b.stack)
		exit(0);
	if ((ac > 2) && check_isdigit(av) && check_int(av, &stack_a)
		&& check_duplicate(&stack_a) && !check_sorting(&stack_a))
	{
		if (ac == 3)
			swap(&stack_a, "sa\n");
		else
			mini_sort(&stack_a, &stack_b);
	}
	else
		ft_printf("Error\n");
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}
