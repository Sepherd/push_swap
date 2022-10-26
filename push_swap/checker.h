/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:12:42 by arecce            #+#    #+#             */
/*   Updated: 2022/10/25 15:37:13 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_reading(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_backup(char *save);
char	*get_next_line(int fd);
int		checker_int_check(t_stack *a, int ac);
int		checker_digit(char ***str, int i);
int		checker_dup(t_stack *array);
int		checker_sort(t_stack *array);
int		checker_util(char ***str, int i);
void	mem_checker(t_stack *a, t_stack *b);
void	c_free_arg(t_stack *a, int ac);
void	checker_free(t_stack *a, t_stack *b);
int		ft_strcmp(char *s1, char *s2);
void	ko_print(void);
void	make_moves(t_stack *a, t_stack *b, char *moves);
void	check_push_swap(t_stack *a, t_stack *b);
void	c_swap(t_stack *array);
void	c_rotate(t_stack *array);
void	c_reverse(t_stack *array);
void	c_double_move(t_stack *first, t_stack *second, int move);
void	c_push(t_stack *pusher, t_stack *pushed);

#endif