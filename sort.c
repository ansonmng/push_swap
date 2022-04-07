/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:20 by nansonm           #+#    #+#             */
/*   Updated: 2022/03/30 14:25:31 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	sort3(t_list **stack)
{
	const int	num_1 = ft_atoi((*stack)->content);
	const int	num_2 = ft_atoi((*stack)->next->content);
	const int	num_3 = ft_atoi((*stack)->next->next->content);

	if (num_1 == stack_min(*stack) && num_2 == stack_max(*stack))
	{
		run("sa", stack, 0, 1);
		run("ra", stack, 0, 1);
	}
	else if (num_2 == stack_min(*stack) && num_3 == stack_max(*stack))
		run("sa", stack, 0 ,1);
	else if (num_3 == stack_min(*stack) && num_2 == stack_max(*stack))
		run("rra", stack, 0, 1);
	else if (num_2 == stack_min(*stack) && num_1 == stack_max(*stack))
		run("ra", stack, 0, 1);
	else
	{
		run("sa", stack, 0, 1);
		run("rra", stack, 0, 1);
	}
}

static void sort_big(t_list **stack_a)
{
	int	a;
	int	b;
	t_list	*stack_b;

	stack_b = 0;
	while (ft_lstsize(*stack_a) > 3)
		run("pb", stack_a, &stack_b, 1);
	if(!is_sorted(*stack_a))
		sort3(stack_a);
	while (ft_lstsize(stack_b))
	{
		a = 0; 
		b = 0;
		get_min_rotate(*stack_a, stack_b, &a, &b);
		if((a >= 0 && b >= 0) || (a < 0 && b < 0))
			rotate_same(stack_a, &stack_b, a, b);
		else
			rotate_diff(stack_a, &stack_b, a, b);
		run ("pa", &stack_b, stack_a, 1);
	}
}

static void	sort_final(t_list **stack)
{
	const int i = index_minmax(*stack, stack_min(*stack));
	if (i < 0)
		run("rra", stack, 0, -i);
	else
		run("ra", stack, 0, i);
}

void	sort(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		run("sa", stack, 0, 1);
	else if (ft_lstsize(*stack) == 3)
		sort3(stack);
	else
		sort_big(stack);
	sort_final(stack);
}