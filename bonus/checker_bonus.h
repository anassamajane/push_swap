/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:08:38 by anaamaja          #+#    #+#             */
/*   Updated: 2025/03/15 22:47:27 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/* operations */
void				_push(t_stack **stack_to, t_stack **stack_from);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

void				_swap(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

void				_rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

void				_reverse_rotate(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

/* parsing */
int					parse_array(char **arr, t_stack **stack);
int					parse_string(char *input, t_stack **stack);
t_stack				*parse_args(char **inputs, int size);
long				my_atol(const char *str);
int					is_valid(char *str);
void				free_arr(char **arr);

/* libft helpers */
t_stack				*create_node(int value);
void				add_back(t_stack **stack, t_stack *new);
void				clear_list(t_stack **stack);
int					stack_size(t_stack *stack);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
int					ft_strcmp(char *s1, char *s2);

/* checker */
void				read_and_execute(t_stack **stack_a, t_stack **stack_b);
void				final_check_bonus(t_stack *stack_a, t_stack *stack_b);
int					execute_instruction(char *cmd, t_stack **stack_a,
						t_stack **stack_b);
int					check_duplicate(t_stack *stack);
int					already_sorted(t_stack *stack_a);
#endif
