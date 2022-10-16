/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:28:20 by arecce            #+#    #+#             */
/*   Updated: 2022/10/16 15:15:36 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_or_rev_a(t_stack *a, t_stack *b)
{
	if (b->target_pos <= a->size / 2)
		rotate(a, "ra\n");
	else
		reverse(a, "rra\n");
}

void	rot_or_rev_b(t_stack *b)
{
	if (b->pos <= b->size / 2)
		rotate(b, "rb\n");
	else
		reverse(b, "rrb\n");
}

void	little_move(t_stack *a)
{
	if (a->pos_min <= a->size / 2)
		rotate(a, "ra\n");
	else
		reverse(a, "rra\n");
}

void	empty_b_stack(t_stack *a, t_stack *b)
{
	if (b->value > a->value && b->value < find_bigger(a)
		&& a->stack[a->size - 1] == a->value)
	{
		while (b->stack[0] != b->value)
			rot_or_rev_b(b);
		push(b, a, "pa\n");
	}
	else if (b->value > find_bigger(a))
	{
		while (a->stack[0] != find_little(a))
			little_move(a);
		while (b->stack[0] != b->value)
			rot_or_rev_b(b);
		push(b, a, "pa\n");
	}
	else
	{
		save_move(a, b);
		while (a->stack[0] != a->value)
			rot_or_rev_a(a, b);
		while (b->stack[0] != b->value)
			rot_or_rev_b(b);
		push(b, a, "pa\n");
	}
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
	}
	while (a->stack[0] != find_little(a))
	{
		if (a->pos_min <= a->size / 2)
			rotate(a, "ra\n");
		else
			reverse(a, "rra\n");
	}
}
