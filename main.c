/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:26:40 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/14 17:02:36 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (1);
	}
	return (final_check(&stack_a, &stack_b));
}
