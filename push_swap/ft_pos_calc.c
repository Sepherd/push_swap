/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:51 by arecce            #+#    #+#             */
/*   Updated: 2022/10/06 18:21:34 by arecce           ###   ########.fr       */
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

	i = 0;
	while (i != arr_b->index + 1)
		i++;
	arr_a->index = i;
}

void	get_pos(t_stack *arr)
{
	int	i;

	i = 0;
	while (arr->stack[i] != arr->value)
		i++;
	arr->pos = i;
}

void	get_target_pos(t_stack *arr_a, t_stack *arr_b)
{
	int	i;

	i = 0;
	while (i != arr_a->index)
		i++;
	arr_b->target_pos = i;
}

void	get_all_pos(t_stack *arr_a, t_stack *arr_b, t_stack *temp, int i)
{
	arr_b->value = arr_b->stack[i];
	get_index(arr_b, temp);
	get_target_index(arr_a, arr_b, temp);
	get_pos(arr_b);
	get_target_pos(arr_a, arr_b);
}
