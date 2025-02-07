/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:36:19 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/07 18:19:06 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "push_swap.h"

int	already_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = *stack_a;
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
	return (1);
}

int	final_check(t_stack **stack_a, t_stack **stack_b)
{
	int	*sorted;
	int	size;

	sorted = stack_to_arr(*stack_a);
	size = stack_size(*stack_a);
}*/
