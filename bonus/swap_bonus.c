/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:00:05 by anaamaja          #+#    #+#             */
/*   Updated: 2025/03/15 03:07:48 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	_swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	_swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	_swap(stack_a);
	_swap(stack_b);
}
