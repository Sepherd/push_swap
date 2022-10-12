/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:28:20 by arecce            #+#    #+#             */
/*   Updated: 2022/10/12 18:00:33 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	empty_b_stack(t_stack *a, t_stack *b)
{
	/* ft_printf("b value: %d\n", b->value);
	ft_printf("a value: %d\n", a->value);
	ft_printf("b target pos: %d\n", b->target_pos);
	ft_printf("b index: %d\n", b->index);
	ft_printf("a index: %d\n", a->index); */
	/* if (b->target_pos == 0 && b->value > a->value)
	{
		push(b, a, "pa\n");
		rotate(a, "ra\n");
	}
	else if (b->target_pos == 0)
	{
		reverse(a, "rra\n");
		push(b, a, "pa\n");
	}
	else if (b->target_pos > a->size / 2)
	{
		while (a->stack[0] != a->value)
			reverse(a, "rra\n");
	}
	else
	{
		while (a->stack[0] != a->value)
			rotate(a, "ra\n");
		push(b, a, "pa\n");
	}
	if (b->pos <= b->size / 2 && b->pos != 0)
	{
		while (b->stack[0] != b->value)
			rotate(b, "rb\n");
		push(b, a, "pa\n");
	}
	else if (b->pos > b->size / 2 && b->pos != 0)
	{
		while (b->stack[0] != b->value)
			reverse(b, "rrb\n");
		push(b, a, "pa\n");
	} */
	if (b->value > find_bigger(a))
	{
		while (a->stack[0] != find_little(a))
			rotate(a, "ra\n");
		while (b->stack[0] != b->value)
		{
			if (b->pos <= b->size / 2)
				rotate(b, "rb\n");
			else
				reverse(b, "rrb\n");
		}
		push(b, a, "pa\n");
	}
	else if (b->value > a->value && b->target_pos == 0
		&& a->stack[a->size - 1] == a->value)
	{
		while (b->stack[0] != b->value)
		{
			if (b->pos <= b->size / 2)
				rotate(b, "rb\n");
			else
				reverse(b, "rrb\n");
		}
		push(b, a, "pa\n");
	}
	else
	{
		while (a->stack[0] != a->value)
		{
			if (b->target_pos <= a->size / 2)
				rotate(a, "ra\n");
			else
				reverse(a, "rra\n");
		}
		while (b->stack[0] != b->value)
		{
			if (b->pos <= b->size / 2)
				rotate(b, "rb\n");
			else
				reverse(b, "rrb\n");
		}
		push(b, a, "pa\n");
	}
	print_stack(a);
}

void	big_sort(t_stack *a, t_stack *b, t_stack *t)
{
	while (a->size > 3)
		push(a, b, "pb\n");
	sort_three(a);
	while (b->size > 0)
	{
		cheap_cost(a, b, t);
		get_all_pos(a, b, t);
		empty_b_stack(a, b);
		/* if (a->stack[0] == 87)
		{
			ft_printf("b target pos: %d\n", b->target_pos);
			break ;
		} */
	}
	while (a->stack[0] != find_little(a))
		rotate(a, "ra\n");
	/******STAMPA******/
	ft_printf("stack a:\n");
	print_stack(a);
}
