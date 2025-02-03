/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:44:14 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/03 17:44:16 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	_rotate(stack_b);
	printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	_rotate(stack_a);
	_rotate(stack_b);
	printf("rr\n");
}
