/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:00:12 by anaamaja          #+#    #+#             */
/*   Updated: 2025/03/15 03:08:10 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	rrb(t_stack **stack_b)
{
	_reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	_reverse_rotate(stack_a);
	_reverse_rotate(stack_b);
}
