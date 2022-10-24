/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:09 by arecce            #+#    #+#             */
/*   Updated: 2022/10/24 18:56:23 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_swap(t_stack *array)
{
	int	temp;

	if (array->size > 1)
	{
		temp = array->stack[0];
		array->stack[0] = array->stack[1];
		array->stack[1] = temp;
	}
}

void	c_rotate(t_stack *array)
{
	int	temp;
	int	i;
	int	size;

	temp = array->stack[0];
	i = 0;
	size = array->size;
	while (--size)
	{
		array->stack[i] = array->stack[i + 1];
		i++;
	}
	array->stack[i] = temp;
}

void	c_reverse(t_stack *array)
{
	int	temp;
	int	i;
	int	size;

	size = array->size - 1;
	i = size;
	temp = array->stack[size];
	while (size--)
	{
		array->stack[i] = array->stack[i - 1];
		i--;
	}
	array->stack[i] = temp;
}

void	c_double_move(t_stack *first, t_stack *second, int move)
{
	if (move == 1)
	{
		c_swap(first);
		c_swap(second);
	}
	if (move == 2)
	{
		c_rotate(first);
		c_rotate(second);
	}
	if (move == 3)
	{
		c_reverse(first);
		c_reverse(second);
	}
}

void	c_push(t_stack *pusher, t_stack *pushed)
{
	pushed->size += 1;
	if (pushed->size > 1)
	{
		c_reverse(pushed);
		pushed->mosse -= 1;
	}
	pushed->stack[0] = pusher->stack[0];
	c_rotate(pusher);
}
