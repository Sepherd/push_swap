/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:24:27 by arecce            #+#    #+#             */
/*   Updated: 2022/10/18 17:10:04 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_util(char ***str, int i)
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
			error_call();
		while (str[i][j][k])
		{
			if (ft_isdigit(str[i][j][k]))
				k++;
			else
				error_call();
		}
		j++;
		len++;
	}
	return (len);
}

void	memory_manage(t_stack *arr_a, t_stack *arr_b, t_stack *ta, t_stack *tb)
{
	arr_b->size = 0;
	ta->size = 0;
	tb->size = arr_a->size;
	arr_a->stack = (int *)malloc(sizeof(int) * arr_a->size);
	arr_b->stack = (int *)malloc(sizeof(int) * arr_a->size);
	ta->stack = (int *)malloc(sizeof(int) * arr_a->size);
	tb->stack = (int *)malloc(sizeof(int) * arr_a->size);
}

void	free_arg(t_stack *a, int ac)
{
	int	i;
	int	k;

	i = 0;
	while (i < ac -1)
	{
		k = 0;
		while (a->arg[i][k])
		{
			free(a->arg[i][k]);
			k++;
		}
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		free(a->arg[i]);
		i++;
	}
	free(a->arg);
}

void	free_manage(t_stack *arr_a, t_stack *arr_b, \
					t_stack *arr_c, t_stack *arr_d)
{
	free(arr_a->stack);
	free(arr_b->stack);
	free(arr_c->stack);
	free(arr_d->stack);
}

void	error_call(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
