/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:41:46 by arecce            #+#    #+#             */
/*   Updated: 2022/10/14 12:32:41 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_stack *array_a, t_stack *array_b, t_stack *temp)
{
	if (array_a->size == 3)
		sort_three(array_a);
	else if (array_a->size == 5)
		sort_five(array_a, array_b);
	else
		big_sort(array_a, array_b, temp);
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
}
