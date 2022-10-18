/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:43 by arecce            #+#    #+#             */
/*   Updated: 2022/10/18 20:19:08 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	get_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a->arg[i])
		i++;
	return (i);
} */

/* void	fill_array(t_stack *a, t_stack *tb)
{
	a->stack = (int *)malloc(sizeof(int) * get_size(a));
	tb->stack = (int *)malloc(sizeof(int) * get_size(a));
	a->size = get_size(a);
	ft_printf("size: %d\n", get_size(a));
	if (check_isdigit(a->arg) && check_int(a->arg, a, tb, 0) && check_dup(a)
		&& !check_sort(a))
		ft_printf("OK!\n");
	else
		ft_printf("KO!\n");
	exit(0);
} */

void	print_stack(t_stack *array)
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
}

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
	if (check_int(&sa, &tb, ac) && check_dup(&sa) && !check_sort(&sa))
	{
		if (sa.size == 2)
			swap(&sa, "sa\n");
		else
			select_sort(&sa, &sb, &ta, &tb);
	}
	else
		error_call();
	free_arg(&sa, ac);
	free_manage(&sa, &sb, &ta, &tb);
	return (0);
}

// leaks -atExit --