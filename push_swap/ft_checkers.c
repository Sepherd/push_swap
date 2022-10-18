/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:21:27 by arecce            #+#    #+#             */
/*   Updated: 2022/10/18 19:53:28 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isdigit(char ***str, int ac)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < ac - 1)
	{
		len += check_util(str, i);
		i++;
	}
	return (len);
}

int	check_int(t_stack *a, t_stack *tb, int ac)
{
	int			i;
	int			k;
	int			j;
	long long	temp;

	temp = 0;
	i = 0;
	k = 0;
	while (k < ac - 1)
	{
		j = 0;
		while (a->arg[k][j])
		{
			temp = ft_atoi(a->arg[k][j]);
			if (temp >= INT_MIN && temp <= INT_MAX)
				copy_int(a, tb, i, temp);
			else
				return (0);
			i++;
			j++;
		}
		k++;
	}
	return (1);
}

int	check_dup(t_stack *array)
{
	int	j;
	int	k;

	k = array->size;
	while (--k)
	{
		j = k - 1;
		while (j >= 0)
		{
			if (array->stack[k] == array->stack[j])
				return (0);
			else
				j--;
		}
	}
	return (1);
}

int	check_sort(t_stack *array)
{
	int	j;
	int	k;

	k = array->size - 1;
	while (k > 0)
	{
		j = k - 1;
		while (j >= 0)
		{
			if (array->stack[k] > array->stack[j])
				j--;
			else
				return (0);
		}
		k--;
	}
	return (1);
}

void	copy_int(t_stack *a, t_stack *tb, int i, long long temp)
{
	a->stack[i] = temp;
	tb->stack[i] = temp;
}
