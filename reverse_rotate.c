/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:43:57 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/03 17:43:59 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*new_last;

	if (!*stack || (*stack)->next == NULL)
		return ;

	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;

	new_last = *stack;
	while (new_last->next != bottom)
		new_last = new_last->next;

	new_last->next = NULL;
	bottom->next = *stack;
	*stack = bottom;
}

void	rra(t_stack **stack_a)
{
	_reverse_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	_reverse_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	_reverse_rotate(stack_a);
	_reverse_rotate(stack_b);
	printf("rrr\n");
}
