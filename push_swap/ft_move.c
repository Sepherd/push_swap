/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:43:18 by arecce            #+#    #+#             */
/*   Updated: 2022/09/14 15:57:35 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(struct s_stack array, char *move)
{
	int	temp;

	if (array.size > 1)
	{
		temp = array.stack[0];
		array.stack[0] = array.stack[1];
		array.stack[1] = temp;
	}
	ft_printf("%s", move);
}

void	rotate(struct s_stack array, char *move)
{
	int	temp;
	int	i;
	int	size;

	temp = array.stack[0];
	i = 0;
	size = array.size;
	while (--size)
	{
		array.stack[i] = array.stack[i + 1];
		i++;
	}
	array.stack[i] = temp;
	ft_printf("%s", move);
}

void	reverse(struct s_stack array, char *move)
{
	int	temp;
	int	i;
	int	size;

	size = array.size - 1;
	i = size;
	temp = array.stack[size];
	while (size--)
	{
		array.stack[i] = array.stack[i - 1];
		i--;
	}
	array.stack[i] = temp;
	ft_printf("%s", move);
}

void	double_move(struct s_stack first, struct s_stack second, int move)
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
	}
	if (move == 3)
	{
		reverse(first, "\0");
		reverse(second, "\0");
		ft_printf("rrr\n");
	}
}

void	push(struct s_stack pusher, struct s_stack pushed, char *move)
{
	pushed.size += 1;
	// ft_printf("pusher size e' %d\n", pushed.size);
	pushed.stack = malloc(sizeof(int) * pushed.size);
	if (pushed.size > 1)
		reverse(pushed, "\0");
	pushed.stack[0] = pusher.stack[0];
	ft_printf("stackb[0] e' %d\n", pushed.stack[0]);
	rotate(pusher, "\0");
	pusher.size -= 1;
	// pusher.stack = malloc(sizeof(int) * pusher.size);
	ft_printf("%s\n", move);
}
