/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 11:13:22 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	if (ft_rotate(stack_a))
		return ;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	if (ft_rotate(stack_b))
		return ;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

int	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return (1);
	first = *stack;
	last = ft_lstlast(first);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}
