/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:31:32 by arecce            #+#    #+#             */
/*   Updated: 2022/10/16 15:13:23 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_move(t_stack *a, t_stack *b)
{
	if (b->target_pos < a->size / 2 && b->pos < b->size / 2)
		while (a->stack[0] != a->value && b->stack[0] != b->value)
			double_move(a, b, 2);
	else if (b->target_pos > a->size / 2 && b->pos > b->size / 2)
		while (a->stack[0] != a->value && b->stack[0] != b->value)
			double_move(a, b, 3);
}
