/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:21:27 by arecce            #+#    #+#             */
/*   Updated: 2022/09/13 18:40:11 by arecce           ###   ########.fr       */
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
		while (str[i][j] != '\0')
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

int	check_int(char **str, struct s_stack array)
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
		{
			array.stack[i] = temp;
			/* ft_printf("%d\n", array.stack[i]); */
		}
		else
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	check_duplicate(struct s_stack array)
{
	int	j;
	int	k;

	k = array.size;
	while (--k)
	{
		j = k - 1;
		while (j >= 0)
		{
			if (array.stack[k] == array.stack[j])
				return (0);
			else
				j--;
		}
	}
	return (1);
}

void	print_stack(struct s_stack array)
{
	int	size;
	int	i;

	size = array.size;
	i = 0;
	while (size--)
	{
		ft_printf("%d\n", array.stack[i]);
		i++;
	}
}
