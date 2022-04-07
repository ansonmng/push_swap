#include "libft/libft.h"

int	stack_min(t_list *stack)
{
	int	min;
	int	num;

	min = ft_atoi(stack->content);
	while(stack)
	{
		num = ft_atoi(stack->content);
		if (min > num)
			min = num;
		stack = stack->next;
	}
	return(min);
}

int	stack_max(t_list *stack)
{
	int	max;
	int	num;

	max = ft_atoi(stack->content);
	while(stack)
	{
		num = ft_atoi(stack->content);
		if(max < num)
			max = num;
		stack = stack->next;
	}
	return(max);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}