/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:07:24 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/07 17:07:25 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static void	ps_free(char **string)
{
	int	i;

	i = 0;
	while (string[i])
		free(string[i++]);
	free(string);
}

int	main(int argc, char **argv)
{
	int		len;
	char	**str;
	t_list	*stack;

	if (argc > 1)
	{
		str = 0;
		len = handling_argv(&str, argv + 1, " ");
		if (!is_valid(str) || !len)
		{
			ps_free(str);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		stack = 0;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(str[len]));
		if (!is_sorted(stack))
			sort(&stack);
		ft_lstclear(&stack, free);
		free(str);
	}
	return (0);
}
