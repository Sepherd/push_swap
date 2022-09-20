/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:41:46 by arecce            #+#    #+#             */
/*   Updated: 2022/09/20 18:27:26 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	mini_sort(t_stack *array_a, t_stack *array_b)
{
	if (array_a->size == 3)
		sort_three(array_a);
	else if (array_a->size == 5)
		sort_five(array_a, array_b);
	else
		sort_hundred(array_a, array_b);
}

void	sort_three(t_stack *array)
{
	while (!check_sorting(array))
	{
		if (array->stack[0] > array->stack[1]
			&& array->stack[0] < array->stack[2])
			swap(array, "sa\n");
		else if (array->stack[0] < array->stack[1]
			&& array->stack[0] < array->stack[2])
		{
			swap(array, "sa\n");
			rotate(array, "ra\n");
		}
		else if (array->stack[0] < array->stack[1]
			&& array->stack[0] > array->stack[2])
			reverse(array, "rra\n");
		else if (array->stack[0] < array->stack[1]
			&& array->stack[1] > array->stack[2])
		{
			rotate(array, "ra\n");
			swap(array, "sa\n");
		}
		else
			rotate(array, "ra\n");
	}
}

void	sort_five(t_stack *array_a, t_stack *array_b)
{
	push_little(array_a, array_b);
	push_bigger(array_a, array_b);
	sort_three(array_a);
	push(array_b, array_a, "pa\n");
	rotate(array_a, "ra\n");
	push(array_b, array_a, "pa\n");
	print_stack(array_a);
}

void	sort_hundred(t_stack *array_a, t_stack *array_b)
{
	while (array_a->size > 0)
		push_little(array_a, array_b);
	while (array_b->size > 0)
		push(array_b, array_a, "pa\n");
	// print_stack(array_a);
	ft_printf("mosse a %d\n", array_a->mosse);
	ft_printf("mosse b %d\n", array_b->mosse);
	ft_printf("mosse totali %d\n", array_a->mosse + array_b->mosse);
}
