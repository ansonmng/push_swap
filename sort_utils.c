/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:58:31 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/07 16:58:32 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	stack_min(t_list *stack)
{
	int	min;
	int	num;

	min = ft_atoi(stack->content);
	while (stack)
	{
		num = ft_atoi(stack->content);
		if (min > num)
			min = num;
		stack = stack->next;
	}
	return (min);
}

int	stack_max(t_list *stack)
{
	int	max;
	int	num;

	max = ft_atoi(stack->content);
	while (stack)
	{
		num = ft_atoi(stack->content);
		if (max < num)
			max = num;
		stack = stack->next;
	}
	return (max);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_abs(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}
