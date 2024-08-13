/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:14:53 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 11:01:43 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	if (ft_swap(stack_a))
		return ;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	if (ft_swap(stack_b))
		return ;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

int	ft_swap(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	int		tmp;

	if (ft_lstsize(*stack) < 2)
		return (1);
	current = *stack;
	next = current->next;
	tmp = current->value;
	current->value = next->value;
	next->value = tmp;
	tmp = current->index;
	current->index = next->index;
	next->index = tmp;
	return (0);
}
