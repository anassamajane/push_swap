/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:17:29 by anaamaja          #+#    #+#             */
/*   Updated: 2025/03/15 03:09:29 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	parse_array(char **arr, t_stack **stack)
{
	int		i;
	long	num;
	t_stack	*new_node;

	i = 0;
	while (arr[i])
	{
		if (!is_valid(arr[i]))
			return (0);
		num = my_atol(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		new_node = create_node((int)num);
		if (!new_node)
			return (0);
		add_back(stack, new_node);
		i++;
	}
	return (1);
}

int	parse_string(char *input, t_stack **stack)
{
	char	**arr;

	arr = ft_split(input, ' ');
	if (!arr || !arr[0])
	{
		free_arr(arr);
		return (0);
	}
	if (!parse_array(arr, stack))
	{
		free_arr(arr);
		return (0);
	}
	free_arr(arr);
	return (1);
}

t_stack	*parse_args(char **inputs, int size)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		if (!parse_string(inputs[i], &stack))
		{
			clear_list(&stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
