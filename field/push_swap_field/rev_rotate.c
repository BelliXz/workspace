/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 11:27:06 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	if (ft_rev_rotate(stack_a))
		return ;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	if (ft_rev_rotate(stack_b))
		return ;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return ;
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return (1);
	first = *stack;
	last = ft_lstlast(first);
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}
