/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:29:30 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/07 16:48:23 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

/* push_swap_utils.c */
int		is_valid(char **string);
int		is_sorted(t_list *stack);
int		handling_argv(char ***string, char **argv, char *chr);
/* instructions.c */
void	run(char *cmd, t_list **stack_1, t_list **stack_2, int x);
/* sort.c */
void	sort(t_list **stack);
/* sort_utils.c */
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);
int		min(int a, int b);
int		ft_abs(int num);
/* sort_big_utils.c */
int		index_minmax(t_list *stack, int num);
void	get_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);
#endif
