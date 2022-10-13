/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:43 by arecce            #+#    #+#             */
/*   Updated: 2022/10/13 12:44:06 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	temp_a;
	t_stack	temp_b;

	if (ac == 1 || ac == 2)
		exit(0);
	memory_manage(&stack_a, &stack_b, ac);
	memory_manage(&temp_b, &temp_a, ac);
	if (!stack_a.stack || !stack_b.stack)
		exit(0);
	if ((ac > 2) && check_isdigit(av) && check_int(av, &stack_a, &temp_b)
		&& check_duplicate(&stack_a) && !check_sorting(&stack_a))
	{
		sort_easy(&temp_a, &temp_b);
		if (ac == 3)
			swap(&stack_a, "sa\n");
		else
			mini_sort(&stack_a, &stack_b, &temp_a);
		/* if (check_sorting(&stack_a))
			ft_printf("OK\n"); */
	}
	else
		ft_printf("Error\n");
	free_manage(&stack_a, &stack_b, &temp_a, &temp_b);
	return (0);
}

// leaks -atExit --