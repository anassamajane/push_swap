/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:01:18 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/14 17:25:42 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_into_b(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int	size_b;

	if (!*stack_a)
		return ;
	size_b = stack_size(*stack_b);
	while (1)
	{
		if ((*stack_a)->value <= min)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			return ;
		}
		else if (*stack_a && (*stack_a)->value <= max)
		{
			pb(stack_a, stack_b);
			if (size_b > 1 && (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b);
			return ;
		}
		else
			ra(stack_a);
	}
}

void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	big_index;

	size = stack_size(*stack_b);
	while (size > 0)
	{
		big_index = index_of_largest_value(*stack_b);
		ops_to_back_to_a(stack_a, stack_b, big_index);
		size--;
	}
}

void	sorting_algo(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int	i;
	int	j;
	int	size;
	int	temp;

	i = 0;
	size = stack_size(*stack_a);
	temp = size;
	if (size > 100)
		j = size / 13;
	else
		j = size / 6;
	while (temp > 0)
	{
		push_into_b(stack_a, stack_b, arr[i], arr[j]);
		if (i < j)
			i++;
		if (j < size - 1)
			j++;
		temp--;
	}
	back_to_a(stack_a, stack_b);
}
