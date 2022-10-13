/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:46 by arecce            #+#    #+#             */
/*   Updated: 2022/10/13 19:26:13 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	cost_b_calc(t_stack *arr)
{
	if (arr->pos <= arr->size / 2)
		arr->cost_b = arr->size - (arr->size - arr->pos);
	else
		arr->cost_b = (arr->pos - arr->size) * -1;
}

void	cost_a_calc(t_stack *arr_a, t_stack *arr_b)
{
	if (arr_b->value > find_bigger(arr_a)
		&& arr_a->stack[arr_a->size - 1] == find_little(arr_a))
		arr_b->cost_a = 0;
	else if ()
	else if (arr_b->target_pos <= arr_a->size / 2)
		arr_b->cost_a = arr_a->size - (arr_a->size - arr_b->target_pos);
	else
		arr_b->cost_a = (arr_b->target_pos - arr_a->size) * -1;
}

void	cheap_cost(t_stack *arr_a, t_stack *arr_b, t_stack *temp)
{
	int	i;
	int	cheap;
	int	t_cost;
	int	to_move;

	i = 0;
	cheap = 1000;
	t_cost = 0;
	to_move = 0;
	while (i < arr_b->size)
	{
		arr_b->value = arr_b->stack[i];
		get_all_pos(arr_a, arr_b, temp);
		cost_b_calc(arr_b);
		cost_a_calc(arr_a, arr_b);
		/* ft_printf("b value: %d\n", arr_b->value);
		ft_printf("a size: %d\n", arr_a->size);
		ft_printf("b target pos: %d\n", arr_b->target_pos);
		ft_printf("b cost a: %d\n", arr_b->cost_a);
		ft_printf("b cost b: %d\n", arr_b->cost_b); */
		t_cost = arr_b->cost_a + arr_b->cost_b;
		// ft_printf("b t cost: %d\n", t_cost);
		if (t_cost < cheap)
		{
			cheap = t_cost;
			to_move = i;
		}
		i++;
	}
	arr_b->value = arr_b->stack[to_move];
	/* ft_printf("to_move: %d\n", to_move);
	ft_printf("b value: %d\n", arr_b->value); */
}
