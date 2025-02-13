/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:01:18 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/13 09:44:07 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_sorting(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_arr(t_stack *stack)
{
	int	size;
	int	*arr;
	int	i;
	t_stack	*walk;

	size = stack_size(stack);
	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	walk = stack;
	while (walk)
	{
		arr[i++] = walk->value;
		walk = walk->next;
	}
	array_sorting(arr, size);
	return (arr);
}

void	push_into_b(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int	size_b;

	if (!*stack_a)
		return ;
	size_b = stack_size(*stack_b);
	while (1)
	{
		if((*stack_a)->value <= min)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			return ;
		}
		else if (*stack_a && (*stack_a)->value <= max)
		{
			pb(stack_a, stack_b);
			if (size_b > 1 && (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b);
			return ;
		}
		else
			ra(stack_a);
	}	
}

int	calcul_ops(t_stack *stack_b, int big_index)
{
	int	size;

	size = stack_size(stack_b);
	if (big_index > size / 2)
		return (big_index - size);
	else
		return (big_index);
}

void	operations_needed_to_back_to_a(t_stack **stack_a, t_stack **stack_b, int big_index)
{
	int	operations;

	operations = calcul_ops(*stack_b, big_index);
	while (operations > 0)
	{
		rb(stack_b);
		operations--;
	}
	while (operations < 0)
	{
		rrb(stack_b);
		operations++;
	}
	pa(stack_a, stack_b);
}

void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	big_index;

	size = stack_size(*stack_b);
	while (size > 0)
	{
		big_index = index_of_largest_value(*stack_b);
		operations_needed_to_back_to_a(stack_a, stack_b, big_index);
		size--;
	}
}

void	sorting_algo(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int	i;
	int	j;
	int	size;
	int	temp;

	i = 0;
	size = stack_size(*stack_a);
	temp = size;
	if (size > 100)
		j = size / 13;
	else
		j = size / 6 ;
	while (temp > 0)
	{
		push_into_b(stack_a, stack_b, arr[i], arr[j]);
		if (i < j)
			i++;
		if (j < size - 1)
			j++;
		temp--;
	}
	back_to_a(stack_a, stack_b);
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
	t_stack	*stack_a;
	t_stack	*stack_b;
	//int	size_a;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_args(&av[1], ac - 1);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	//size_a = stack_size(stack_a);
	//print_stack(stack_a);
	final_check(&stack_a, &stack_b);
	//print_stack(stack_a);
}
