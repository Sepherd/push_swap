/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:51 by arecce            #+#    #+#             */
/*   Updated: 2022/10/12 14:38:24 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_index(t_stack *arr, t_stack *temp)
{
	int	i;

	i = 0;
	while (temp->stack[i] != arr->value)
		i++;
	arr->index = i;
}

void	get_target_index(t_stack *arr_a, t_stack *arr_b, t_stack *temp)
{
	int	i;
	int	k;

	i = arr_b->index + 1;
	if (i > temp->size - 1)
	{
		arr_a->index = 0;
		arr_a->pos = arr_a->size - 1;
		arr_a->value = arr_a->stack[arr_a->size - 1];
	}
	else
	{
		while (i < temp->size)
		{
			k = 0;
			while (k < arr_a->size)
			{
				if (arr_a->stack[k] == temp->stack[i])
				{
					arr_a->index = i;
					arr_b->target_pos = k;
					arr_a->value = arr_a->stack[k];
					return ;
				}
				k++;
			}
			i++;
		}
	}
}

void	get_pos(t_stack *arr)
{
	int	i;

	i = 0;
	while (arr->stack[i] != arr->value)
		i++;
	arr->pos = i;
}

void	get_big_pos(t_stack *arr_a, t_stack *arr_b)
{
	if (arr_b->target_pos == arr_a->size - 1 && arr_b->value > arr_a->value)
		arr_b->target_pos = 0;
}

void	get_all_pos(t_stack *arr_a, t_stack *arr_b, t_stack *temp)
{
	get_index(arr_b, temp);
	get_target_index(arr_a, arr_b, temp);
	get_pos(arr_b);
	get_big_pos(arr_a, arr_b);
}
