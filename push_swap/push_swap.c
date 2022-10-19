/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:43 by arecce            #+#    #+#             */
/*   Updated: 2022/10/19 18:23:04 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_stack(t_stack *array)
{
	int	size;
	int	i;

	size = array->size - 1;
	i = 0;
	while (i <= size)
	{
		ft_printf("%d ", array->stack[i]);
		i++;
	}
	ft_printf("\n");
} */

void	init(char **av, t_stack *a, int ac)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	a->arg = malloc(sizeof(char **) * ac - 1);
	while (k < ac - 1)
	{
		a->arg[k] = ft_split(av[i], ' ');
		i++;
		k++;
	}
	a->size = check_isdigit(a->arg, ac);
}

int	main(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;
	t_stack	ta;
	t_stack	tb;

	if (ac < 2)
		exit(0);
	init(av, &sa, ac);
	memory_manage(&sa, &sb, &ta, &tb);
	if (check_int(&sa, &tb, ac) && check_dup(&sa))
	{
		if (!check_sort(&sa))
		{
			if (sa.size == 2)
				swap(&sa, "sa\n");
			else
				select_sort(&sa, &sb, &ta, &tb);
		}
	}
	else
		error_call();
	free_arg(&sa, ac);
	free_manage(&sa, &sb, &ta, &tb);
	return (0);
}

// leaks -atExit --