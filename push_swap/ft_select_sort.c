/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:41:46 by arecce            #+#    #+#             */
/*   Updated: 2022/10/14 12:32:41 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_stack *sa, t_stack *sb, t_stack *ta, t_stack *tb)
{
	if (sa->size == 3)
		sort_three(sa);
	else if (sa->size == 5)
		sort_five(sa, sb);
	else
	{
		sort_easy(ta, tb);
		big_sort(sa, sb, ta);
	}
}

void	sort_three(t_stack *array)
{
	while (!check_sort(array))
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

void	sort_five(t_stack *sa, t_stack *sb)
{
	push_little(sa, sb);
	push_bigger(sa, sb);
	sort_three(sa);
	push(sb, sa, "pa\n");
	rotate(sa, "ra\n");
	push(sb, sa, "pa\n");
}
