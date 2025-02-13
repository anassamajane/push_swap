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
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	_reverse_rotate(stack_a);
	_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
