/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:43:01 by arecce            #+#    #+#             */
/*   Updated: 2022/10/24 19:23:04 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ko_print(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

void	mem_checker(t_stack *a, t_stack *b)
{
	b->size = 0;
	a->stack = (int *)malloc(sizeof(int) * a->size);
	b->stack = (int *)malloc(sizeof(int) * a->size);
}

void	checker_free(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
}
