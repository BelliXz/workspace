/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:01:00 by paradari          #+#    #+#             */
/*   Updated: 2024/08/03 14:01:03 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

void	ft_free_stack(t_stack **stack);
void	ft_error(t_stack **a);
int		ft_check(char *str);
int		ft_check_dup(t_stack *stack, int num);

void	ft_set_node(t_stack **stack, int n);
void	ft_init_stack(t_stack **a_stack, int ac, char **av);

void	ft_free(char **temp);
int		ft_issort(t_stack *a_stack);
void	check_n_sort(t_stack *a_stack);

void	ft_sort_3(t_stack **a_stack);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
int		ft_find_max(t_stack **stack);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
int		ft_push(t_stack **s_to, t_stack **s_from);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
int		ft_swap(t_stack **stack);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
int		ft_rotate(t_stack **stack);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rev_rotate(t_stack **stack);

#endif
