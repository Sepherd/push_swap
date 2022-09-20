/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:24:16 by arecce            #+#    #+#             */
/*   Updated: 2022/09/20 16:47:01 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_bigger(t_stack *array)
{
	int	i;
	int	big;

	i = 0;
	big = array->stack[0];
	while (i < array->size)
	{
		if (array->stack[i] > big)
		{
			big = array->stack[i];
			array->pos_max = i;
		}
		i++;
	}
	return (big);
}

void	push_bigger(t_stack *array_a, t_stack *array_b)
{
	int	big;
	int	len;

	big = find_bigger(array_a);
	len = array_a->size / 2;
	while (array_a->stack[0] != big)
	{
		if (array_a->pos_min > len)
			rotate(array_a, "ra\n");
		else
			reverse(array_a, "rra\n");
	}
	push(array_a, array_b, "pb\n");
}

int	find_little(t_stack *array)
{
	int	i;
	int	little;

	i = 0;
	little = array->stack[0];
	while (i < array->size)
	{
		if (array->stack[i] < little)
		{
			little = array->stack[i];
			array->pos_min = i;
		}
		i++;
	}
	return (little);
}

void	push_little(t_stack *array_a, t_stack *array_b)
{
	int	little;
	int	len;

	little = find_little(array_a);
	while (array_a->stack[0] != little)
	{
		len = array_a->size / 2;
		if (array_a->pos_min <= len)
			rotate(array_a, "ra\n");
		else
			reverse(array_a, "rra\n");
	}
	push(array_a, array_b, "pb\n");
}
