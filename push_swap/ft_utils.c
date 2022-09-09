/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:21:27 by arecce            #+#    #+#             */
/*   Updated: 2022/09/09 22:25:47 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_isdigit(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '+' || str[i][j] == '-' || ft_isdigit(str[i][j]))
				j++;
		else
			return (0);
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_int(char **str, int *array)
{
	int			i;
	int			j;
	long long	temp;

	temp = 0;
	i = 0;
	j = 1;
	while (str[j])
	{
		temp = ft_atoi(str[j]);
		if (temp >= INT_MIN && temp <= INT_MAX)
			array[i] = temp;
		else
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	check_duplicate(struct s_stack array)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	/* array.size = sizeof(array.stack) / sizeof(array.stack[0]);
	ft_printf("size uguale a %d\n", array.size); */
	while (array.size--)
	{
		if (array.stack[i] == array.stack[j])
			return (0);
		else
		{
			i++;
			j++;
		}
	}
	return (1);
}
