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

void	make_positive(int nb_a, nb_b)
{
	if (nb_a < 0)
		nb_a *= -1;
	if (nb_b < 0)
		nb_b *= -1; 
}

void	cost_b_calc(t_stack *arr)
{
	arr->cost_b = arr->pos;
	if (arr->pos > arr->size / 2)
		arr->cost_b = (arr->size - arr->pos) * -1;
}

void	cost_a_calc(t_stack *arr_a, t_stack *arr_b)
{
	arr_b->cost_a = arr_b->target_pos;
	if (arr_b->target_pos > arr_a->size / 2)
		arr_b->cost_a = (arr_a->size - arr_b->target_pos) * -1;
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
		make_positive(arr_b->cost_a, arr_b->cost_b);
		t_cost = arr_b->cost_a + arr_b->cost_b;
		if (t_cost < cheap)
		{
			cheap = t_cost;
			to_move = i;
		}
		i++;
	}
	arr_b->value = arr_b->stack[to_move];
}
