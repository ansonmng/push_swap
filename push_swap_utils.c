#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

static int	is_int(char *string)
{
	int	i;
	
	i = 0;
	if (string[i] == '+' || string[i] == '-')
		++i;
	while (string[i])
		if(!ft_isdigit(string[i++]))
			return (0);
	if (ft_atoi(string) < INT_MIN || ft_atoi(string) > INT_MAX)
		return (0);
	return (1);
}

static int	has_duplicate(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if(nums[i] == nums[j++])
				return(1);
		}
		i ++;
	}
	return (0);
}

int	handling_argv(char ***string, char **argv, char *chr)
{
	int	i;
	char	*tmp;
	char	*str;

	str = 0;
	while(*argv)
	{
		if (!str)
			str = ft_strdup(*argv++);
		else
		{
			tmp = str;
			str = ft_strjoin(str, chr);
			free(tmp);
			tmp = str;
			str = ft_strjoin(str, *argv++);
			free(tmp);
		}
	}
	*string = ft_split(str, *chr);
	free(str);
	i = 0;
	while ((*string)[i])
		i++;
	return (i);
}

int	is_valid(char **string)
{
	int	i;
	int	tmp;
	int	ret;
	int	*nums;

	i = 0;
	ret = 0;
	while (string[i])
		if (!is_int(string[i++]))
			return (ret);
	nums = malloc(sizeof(int) * i);
	if (!nums)
		return (ret);
	tmp = i;
	while (i --)
		nums [i] = ft_atoi(string[i]);
	if (!has_duplicate(nums, tmp))
		ret = 1;
	free(nums);
	return (ret);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

