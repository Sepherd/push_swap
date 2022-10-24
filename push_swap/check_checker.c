/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:00:59 by arecce            #+#    #+#             */
/*   Updated: 2022/10/24 19:20:02 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker_digit(char ***str, int ac)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < ac - 1)
	{
		len += checker_util(str, i);
		i++;
	}
	return (len);
}

int	checker_util(char ***str, int i)
{
	int	j;
	int	k;
	int	len;

	j = 0;
	len = 0;
	while (str[i][j])
	{	
		k = 0;
		if (str[i][j][k] == '+' || str[i][j][k] == '-'
			|| ft_isdigit(str[i][j][k]))
				k++;
		else
			return (0);
		while (str[i][j][k])
		{
			if (ft_isdigit(str[i][j][k]))
				k++;
			else
				return (0);
		}
		j++;
		len++;
	}
	return (len);
}

int	checker_int_check(t_stack *a, int ac)
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
				a->stack[i] = temp;
			else
				return (0);
			i++;
			j++;
		}
		k++;
	}
	return (1);
}

int	checker_dup(t_stack *array)
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

int	checker_sort(t_stack *array)
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
