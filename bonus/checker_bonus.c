/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:42:11 by anaamaja          #+#    #+#             */
/*   Updated: 2025/03/15 01:42:13 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

void    read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
    char    *line;

    line = get_next_line(0);
    while (line)
    {
        if (!execute_instruction(line, stack_a, stack_b))
        {
            free(line);
            write (2, "Error\n", 6);
            clear_list(stack_a);
            clear_list(stack_b);
            exit(1);
        }
        free(line);
        line = get_next_line(0);
    }
}

void    final_check_bonus(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b != NULL || !already_sorted(stack_a))
        write (1, "KO\n", 3);
    else
        write (1, "OK\n", 3);
}

int execute_instruction(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (!ft_strcmp(cmd, "sa\n"))
        sa(stack_a);
    else if (!ft_strcmp(cmd, "sb\n"))
        sb(stack_b);
    else if (!ft_strcmp(cmd, "ss\n"))
        ss(stack_a, stack_b);
    else if (!ft_strcmp(cmd, "pa\n"))
        pa(stack_a, stack_b);
    else if (!ft_strcmp(cmd, "pb\n"))
        pb(stack_a, stack_b);
    else if (!ft_strcmp(cmd, "ra\n"))
        ra(stack_a);
    else if (!ft_strcmp(cmd, "rb\n"))
        rb(stack_b);
    else if (!ft_strcmp(cmd, "rr\n"))
        rr(stack_a, stack_b);
    else if (!ft_strcmp(cmd, "rra\n"))
        rra(stack_a);
    else if (!ft_strcmp(cmd, "rrb\n"))
        rrb(stack_b);
    else if (!ft_strcmp(cmd, "rrr\n"))
        rrr(stack_a, stack_b);
    else
        return (0);
    return (1);
}

int	already_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	if (!current)
		return (1);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int check_duplicate(t_stack *stack)
{
    t_stack *current;
    t_stack *walk;

    current = stack;
    while (current)
    {
        walk = current->next;
        while (walk)
        {
            if (current->value == walk->value)
                return (1);
            walk = walk->next;
        }
        current = current->next;
    }
    return (0);
}