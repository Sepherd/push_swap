/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:28:20 by arecce            #+#    #+#             */
/*   Updated: 2022/10/05 15:06:02 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	big_sort(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push(a, b, "pb\n");
	sort_three(a);
	/******STAMPA******/
	ft_printf("stack a:\n");
	print_stack(a);
	/* ft_printf("stack b:\n");
	print_stack(b); */
}
