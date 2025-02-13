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
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
