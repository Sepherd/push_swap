/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:38:47 by arecce            #+#    #+#             */
/*   Updated: 2022/09/09 22:53:47 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# include "libft/libft.h"

struct	s_stack
{
	int		*stack;
	size_t	tot_size;
	size_t	int_size;
	size_t	size;
};

int	check_isdigit(char **str);
int	check_int(char **str, int *array);
int	check_duplicate(struct s_stack array);

#endif