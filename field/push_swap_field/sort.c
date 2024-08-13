/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 10:44:43 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_stack **stack)
{
	t_stack	*node;
	int		max;
	int		tmp;

	node = *stack;
	max = 0;
	tmp = node->index;
	while (node)
	{
		if (node->index > tmp)
			tmp = node->index;
		node = node->next;
	}
	while ((tmp >> max) != 0)
		max++;
	return (max);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		max;
	int		i;
	int		j;

	node = *stack_a;
	i = 0;
	max = ft_find_max(stack_a);
	while (i < max)
	{
		j = 0;
		while (j < ft_lstsize(node))
		{
			node = *stack_a;
			if (((node->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}