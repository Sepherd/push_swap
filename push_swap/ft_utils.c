/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:24:27 by arecce            #+#    #+#             */
/*   Updated: 2022/10/05 14:36:36 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	memory_manage(t_stack *arr_a, t_stack *arr_b, int ac)
{
	arr_a->size = ac - 1;
	arr_b->size = 0;
	arr_a->stack = (int *)malloc(sizeof(int) * arr_a->size);
	arr_b->stack = (int *)malloc(sizeof(int) * (ac - 1));
}

void	free_manage(t_stack *arr_a, t_stack *arr_b, \
					t_stack *arr_c, t_stack *arr_d)
{
	free(arr_a->stack);
	free(arr_b->stack);
	free(arr_c->stack);
	free(arr_d->stack);
}
