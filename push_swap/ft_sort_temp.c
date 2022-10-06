/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_temp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:34:51 by arecce            #+#    #+#             */
/*   Updated: 2022/10/05 14:17:32 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_easy(t_stack *tb, t_stack *ta)
{
	ta->size += 1;
	if (ta->size > 1)
		reverse(ta, "\0");
	ta->stack[0] = tb->stack[0];
	rotate(tb, "\0");
	tb->size -= 1;
}

void	push_bigger_easy(t_stack *ta, t_stack *tb)
{
	int	big;

	big = find_bigger(tb);
	while (tb->stack[0] != big)
	{
		rotate(tb, "\0");
	}
	push_easy(tb, ta);
}

void	sort_easy(t_stack *ta, t_stack *tb)
{
	int	i;

	i = tb->size - 1;
	while (i >= 0)
	{
		push_bigger_easy(ta, tb);
		i--;
	}	
	print_stack(ta);
}
