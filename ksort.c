#include "push_swap.h"

int	index_of_largest_value(t_stack *stack_a)
{
	t_stack	*current;
	int	max;
	int	max_index;
	int	i;
	
	current = stack_a;
	max = current->value;
	i = 0;
	max_index = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_index = i;
		}
		i++;
		current = current->next;
	}
	return (max_index);
}


void	print_stack(t_stack *stack)
{
	while(stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int	size;

	size = ac - 1;
	stack = parse_args(&av[1], size);
	if (!stack)
	{
		printf("Error\n");
		return (0);
	}
	print_stack(stack);
	clear_list(&stack);
}
