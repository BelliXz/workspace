/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:01:00 by paradari          #+#    #+#             */
/*   Updated: 2024/08/15 11:19:27 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				id;
	struct s_stack	*next;
}	t_stack;

int		ft_init_stack(t_stack **stack, int ac, char **av);
void	ft_index(t_stack **stack);
int		ft_is_sort(t_stack **stack);
void	ft_add_to_stack(char *nbr, t_stack **stack);

int		ft_check_input(char **nbr, t_stack **stack);
int		ft_check_dup(int num, t_stack **stack);
int		ft_is_num(char	**nbr);
int		ft_check_empty(char *args);

void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_2_3(t_stack **stack);
void	ft_sort3(t_stack **stack);
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_sort5(t_stack **stack_a, t_stack **stack_b);
void	ft_radix_b(t_stack **stack_a, t_stack **stack_b, int i, int max);

int		ft_find_max(t_stack **stack);
int		ft_stksize(t_stack *stack);
void	ft_stkadd_back(t_stack **stack, t_stack *to_add);
t_stack	*ft_stklast(t_stack *stack);
t_stack	*ft_stknew(int value);

void	swap(t_stack **stack, char *op);
void	push(t_stack **from, t_stack **to, char *op);
void	rotate(t_stack **stack, char *op);
void	rev_rotate(t_stack **stack, char *op);
void	ft_push_min_min(t_stack **a, t_stack **b);

void	ft_free_array(char **array);
void	ft_free_stack(t_stack **stack);
int		ft_get_pos(t_stack **stack_a);

#endif
