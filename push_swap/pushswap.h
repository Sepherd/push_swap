/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:38:47 by arecce            #+#    #+#             */
/*   Updated: 2022/09/13 19:31:48 by arecce           ###   ########.fr       */
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
	size_t	size;
};

int		check_isdigit(char **str);
int		check_int(char **str, struct s_stack array);
int		check_duplicate(struct s_stack array);
void	swap(struct s_stack array, char *move);
void	rotate(struct s_stack array, char *move);
void	print_stack(struct s_stack array);
void	reverse(struct s_stack array, char *move);
void	double_move(struct s_stack first, struct s_stack second, int move);

#endif