/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:49 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/13 10:33:51 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;
	int	size;

	size = stack_size(*stack_a);
	if (size != 3)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first > third)
		ra(stack_a);
	if (second > first && second > third)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);

}

int	min_pos(t_stack *stack_a)
{
	t_stack	*current;
	int	min;
	int	min_pos;
	int	i;

	current = stack_a;
	min = current->value;
	i = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size_a;
	int	size_b;

	size_a = stack_size(*stack_a);
	if (size_a == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	while (size_a > 3)
	{
		pos = min_pos(*stack_a);
		if (pos <= size_a / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < size_a)
				rra(stack_a);
		pb(stack_a, stack_b);
		size_a--;
	}
	sort_3(stack_a);
	size_b = stack_size(*stack_b);
	while (size_b > 0)
	{
		pa(stack_a, stack_b);
		size_b--;
	}
}
