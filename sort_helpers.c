/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:43:23 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/14 17:10:22 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_largest_value(t_stack *stack_a)
{
	t_stack	*current;
	int		max;
	int		max_index;
	int		i;

	current = stack_a;
	max = current->value;
	i = 0;
	max_index = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_index = i;
		}
		i++;
		current = current->next;
	}
	return (max_index);
}

void	array_sorting(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_arr(t_stack *stack)
{
	int		size;
	int		*arr;
	int		i;
	t_stack	*walk;

	size = stack_size(stack);
	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	walk = stack;
	while (walk)
	{
		arr[i++] = walk->value;
		walk = walk->next;
	}
	array_sorting(arr, size);
	return (arr);
}

int	calcul_ops(t_stack *stack_b, int big_index)
{
	int	size;

	size = stack_size(stack_b);
	if (big_index > size / 2)
		return (big_index - size);
	else
		return (big_index);
}

void	ops_to_back_to_a(t_stack **stack_a, t_stack **stack_b, int big_index)
{
	int	operations;

	operations = calcul_ops(*stack_b, big_index);
	while (operations > 0)
	{
		rb(stack_b);
		operations--;
	}
	while (operations < 0)
	{
		rrb(stack_b);
		operations++;
	}
	pa(stack_a, stack_b);
}
