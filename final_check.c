/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:36:19 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/14 17:01:28 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	if (!current)
		return (1);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_duplicate(int *sorted_arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (sorted_arr[i - 1] == sorted_arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	final_check(t_stack **stack_a, t_stack **stack_b)
{
	int	*sorted;
	int	size;

	sorted = stack_to_arr(*stack_a);
	size = stack_size(*stack_a);
	if (check_duplicate(sorted, size))
	{
		clear_list(stack_a);
		free(sorted);
		write(2, "Error\n", 6);
		return (1);
	}
	if (already_sorted(*stack_a))
	{
		clear_list(stack_a);
		free(sorted);
		return (1);
	}
	if (size > 10)
		sorting_algo(stack_a, stack_b, sorted);
	else
		small_sort(stack_a, stack_b);
	free(sorted);
	clear_list(stack_a);
	return (0);
}
