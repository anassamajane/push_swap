#include "push_swap.h"

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
	printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	_swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	_swap(stack_a);
	_swap(stack_b);
	printf("ss\n");
}
/*
t_list	*creat_node(int value)
{
	t_list	*new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	print_node(t_list *stack)
{
	while (stack)
	{
		printf("%d->", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main()
{
	t_list	*stack_a = creat_node(10);
	stack_a->next = creat_node(20);
	stack_a->next->next = creat_node(30);

	print_node(stack_a);
	sa(&stack_a);
	print_node(stack_a);
}*/
