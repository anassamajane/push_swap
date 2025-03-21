/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:57 by anaamaja          #+#    #+#             */
/*   Updated: 2025/03/15 03:08:00 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!*stack || (*stack)->next == NULL)
		return ;
	top = *stack;
	bottom = *stack;
	*stack = top->next;
	while (bottom->next)
		bottom = bottom->next;
	bottom->next = top;
	top->next = NULL;
}

void	ra(t_stack **stack_a)
{
	_rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	_rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	_rotate(stack_a);
	_rotate(stack_b);
}
