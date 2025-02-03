/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:43:41 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/03 17:43:43 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*top_from;

	if (!*stack_from)
		return ;

	top_from = *stack_from;
	*stack_from = top_from->next;

	top_from->next = *stack_to;
	*stack_to = top_from;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	_push(stack_a, stack_b);
	printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	_push(stack_b, stack_a);
	printf("pb\n");
}
