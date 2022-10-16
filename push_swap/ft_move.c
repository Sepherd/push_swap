/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:40:42 by arecce            #+#    #+#             */
/*   Updated: 2022/10/14 18:40:31 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *array, char *move)
{
	int	temp;

	if (array->size > 1)
	{
		temp = array->stack[0];
		array->stack[0] = array->stack[1];
		array->stack[1] = temp;
	}
	array->mosse += 1;
	ft_printf("%s", move);
}

void	rotate(t_stack *array, char *move)
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
	array->mosse += 1;
	ft_printf("%s", move);
}

void	reverse(t_stack *array, char *move)
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
	array->mosse += 1;
	ft_printf("%s", move);
}

void	double_move(t_stack *first, t_stack *second, int move)
{
	if (move == 1)
	{
		swap(first, "\0");
		swap(second, "\0");
		ft_printf("ss\n");
	}
	if (move == 2)
	{
		rotate(first, "\0");
		rotate(second, "\0");
		ft_printf("rr\n");
		first->mosse -= 1;
		second->mosse -= 1;
	}
	if (move == 3)
	{
		reverse(first, "\0");
		reverse(second, "\0");
		ft_printf("rrr\n");
		first->mosse -= 1;
		second->mosse -= 1;
	}
	first->mosse += 1;
}

void	push(t_stack *pusher, t_stack *pushed, char *move)
{
	pushed->size += 1;
	if (pushed->size > 1)
	{
		reverse(pushed, "\0");
		pushed->mosse -= 1;
	}
	pushed->stack[0] = pusher->stack[0];
	rotate(pusher, "\0");
	pusher->mosse -= 1;
	pusher->size -= 1;
	pusher->mosse += 1;
	ft_printf("%s", move);
}
