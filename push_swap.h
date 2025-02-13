/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:10:22 by anaamaja          #+#    #+#             */
/*   Updated: 2025/02/08 21:21:10 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int	value;
	struct s_stack	*next;
} t_stack;

// operations
void	_push(t_stack **stack_to, t_stack **stack_from);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	_swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	_reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//parsing
int	parse_array(char **arr, t_stack **stack);
int	parse_string(char *input, t_stack **stack);
t_stack	*parse_args(char **inputs, int size);
long	my_atol(const char *str);
int	is_valid(char *str);
void	free_arr(char **arr);

//
int	index_of_largest_value(t_stack *stack_a);
int	*stack_to_arr(t_stack *stack);
void	push_into_b(t_stack **stack_a, t_stack **stack_b, int min, int max);
int	calcul_ops(t_stack *stack_b, int big_index);
void	operations_needed_to_back_to_a(t_stack **stack_a, t_stack **stack_b, int big_index);
void	back_to_a(t_stack **stack_a, t_stack **stack_b);
void	sorting_algo(t_stack **stack_a, t_stack **stack_b, int *arr);
void	print_stack(t_stack *stack);//////
void	small_sort(t_stack **stack_a, t_stack **stack_b);
int	final_check(t_stack **stack_a, t_stack **stack_b);
//libft helpers
t_stack	*create_node(int value);
void	add_back(t_stack **stack, t_stack *new);
void	clear_list(t_stack **stack);
int	stack_size(t_stack *stack);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

#endif
