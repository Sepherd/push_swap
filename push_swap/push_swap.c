/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:43 by arecce            #+#    #+#             */
/*   Updated: 2022/09/09 23:05:12 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	struct s_stack	stack_a;

	if (ac == 1)
		exit(0);
	ft_printf("ac = %d\n", ac);
	stack_a.stack = malloc(sizeof(int) * (ac - 1));
	if (!stack_a.stack)
		exit(0);
	stack_a.tot_size = sizeof(stack_a.stack);
	ft_printf("tot_size = %d\n", stack_a.tot_size);
	stack_a.int_size = sizeof((stack_a.stack)[0]);
	ft_printf("int_size = %d\n", stack_a.int_size);
	stack_a.size = stack_a.tot_size / stack_a.int_size;
	ft_printf("size = %d\n", stack_a.size);
	if (check_isdigit(av))
		ft_printf("%s\n", av[1]);
	if (check_int(av, stack_a.stack))
		ft_printf("%d\n", stack_a.stack[0]);
	if (check_duplicate(stack_a))
		ft_printf("%d\n", stack_a.stack[2]);
	/*if (check_isdigit(av) && check_int(av, stack_a) && check_duplicate(stack_a))
	{
		if (ac == 2)
		{
			ft_printf("%d", stack_a[0]);
			free(stack_a);
			exit(0);
		}
	}
	else
		exit(0); */
	free(stack_a.stack);
	return (0);
}
