/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:28:40 by anaamaja          #+#    #+#             */
/*   Updated: 2025/03/14 23:28:42 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_args(&av[1], ac - 1);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_duplicate(stack_a))
	{
		write (2, "Error\n", 6);
		clear_list(&stack_a);
		clear_list(&stack_b);
		return (0);
	}
	read_and_execute(&stack_a, &stack_b);
	final_check_bonus(stack_a, stack_b);
	clear_list(&stack_a);
	clear_list(&stack_b);
	return (0);
}
