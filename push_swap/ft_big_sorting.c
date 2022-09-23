/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:28:20 by arecce            #+#    #+#             */
/*   Updated: 2022/09/23 17:47:57 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	target_position(int b, t_stack *a)
{
	int	i;
	int	target;

	if (b > a->stack[0] && b < a->stack[1])
		target = 1;
	else if (b > a->stack[0] && b < a->stack[a->size - 1])
		target = a->size -1;
	return (target);
}

void	cost_calc(t_stack *a, t_stack *b)
{
	
}

void	big_sort(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push(a, b, "pb\n");
	sort_three(a);
	
	/******STAMPA******/
	ft_printf("stack a:\n");
	print_stack(a);
	ft_printf("stack b:\n");
	print_stack(b);
}
