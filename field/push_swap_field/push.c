/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 11:20:58 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_a, stack_b))
		return ;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_b, stack_a))
		return ;
	ft_putstr_fd("pb\n", 1);
}

int	ft_push(t_stack **s_to, t_stack **s_from)
{
	t_stack	*tmp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_lstsize(*s_from) == 0)
		return (1);
	head_to = *s_to;
	head_from = *s_from;
	tmp = head_from;
	head_from = head_from->next;
	*s_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*s_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*s_to = tmp;
	}
	return (0);
}
