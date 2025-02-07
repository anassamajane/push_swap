/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:49 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/07 16:51:52 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_than_10(t_stack **stack_a, t_stack **stack_b)
{
	int	*arr;
	int	size;
	int	i;
	t_stack	*current;

	i = 0;
	arr = stack_to_arr(*stack_a);
	size = stack_size(*stack_a);
	while (i < size)
	{
		current = *stack_a;
		while (current)
		{
			if (current->value == arr[i])
			{
				while (*stack_a != current)
					ra(stack_a);
				pb(stack_a, stack_b);
				i++;
				break ;
			}
			current = current->next;
		}
	}
	free(arr);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	less_than_10(stack_a, stack_b);
	back_to_a(stack_a, stack_b);
}
