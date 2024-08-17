/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:40:37 by paradari          #+#    #+#             */
/*   Updated: 2024/08/15 14:40:39 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*tmp;
	int		value;
	int		id;

	if (ft_stksize(*stack) < 2)
		return ;
	first = *stack;
	tmp = first->next;
	value = tmp->value;
	id = tmp->id;
	tmp->value = first->value;
	tmp->id = first->id;
	first->value = value;
	first->id = id;
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	push(t_stack **from, t_stack **to, char *op)
{
	t_stack	*new_from;
	t_stack	*new_to;
	t_stack	*tmp;

	new_from = *from;
	new_to = *to;
	tmp = new_from;
	new_from = new_from->next;
	*from = new_from;
	if (!new_to)
	{
		new_to = tmp;
		new_to->next = NULL;
		*to = new_to;
	}
	else
	{
		tmp->next = new_to;
		*to = tmp;
	}
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	rotate(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = ft_stklast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	rev_rotate(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = ft_stklast(*stack);
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
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_push_min_min(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (count < 2)
	{
		i = ft_get_pos(stack_a);
		if (i < 2)
		{
			j = 0;
			while (j++ < i)
				rotate (stack_a, "ra");
			push(stack_a, stack_b, "pb");
		}
		else
		{
			j = 2;
			while (j++ < i)
				rev_rotate(stack_a, "rra");
			push(stack_a, stack_b, "pb");
		}
		count++;
	}
}
