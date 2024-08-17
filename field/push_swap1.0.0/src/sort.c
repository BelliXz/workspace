/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:40:47 by paradari          #+#    #+#             */
/*   Updated: 2024/08/15 14:40:48 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_first;
	size_t	i;
	size_t	stack_size;
	size_t	max;
	size_t	j;

	a_first = *stack_a;
	i = 0;
	stack_size = ft_stksize(*stack_a);
	max = ft_find_max(stack_a);
	while (i < max)
	{
		j = 0;
		while (j++ < stack_size)
		{
			a_first = *stack_a;
			if (((a_first->id >> i) & 1) == 1)
				rotate(stack_a, "ra");
			else
				push(stack_a, stack_b, "pb");
		}
		while (ft_stksize(*stack_b) != 0)
			push(stack_b, stack_a, "pa");
		i++;
	}
}

void	ft_sort5(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_min_min(stack_a, stack_b);
	ft_sort_2_3(stack_a);
	if (ft_is_sort(stack_b) == 1)
		swap(stack_b, "sb");
	push(stack_b, stack_a, "pa");
	push(stack_b, stack_a, "pa");
}

void	ft_sort3(t_stack **stack)
{
	t_stack	*st;
	t_stack	*nd;
	t_stack	*rd;

	st = *stack;
	nd = st->next;
	rd = nd->next;
	if (st->id > nd->id && st->id < rd->id)
		swap(stack, "sa");
	else if (st->id > nd->id && nd->id > rd->id)
	{
		rotate(stack, "ra");
		swap(stack, "sa");
	}
	else if (st->id > nd->id && nd->id < rd->id && st->id > rd->id)
		rotate(stack, "ra");
	else if (st->id < nd->id && nd->id > rd->id && st->id < rd->id)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
	else if (st->id < nd->id && nd->id > rd->id && st->id > rd->id)
		rev_rotate(stack, "rra");
}

void	ft_sort_2_3(t_stack **stack)
{
	if (ft_stksize(*stack) == 2 && ft_is_sort(stack) == 0)
		swap(stack, "sa");
	else
		ft_sort3(stack);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stksize(*stack_a) <= 3)
		ft_sort_2_3(stack_a);
	else if (ft_stksize(*stack_a) <= 5)
		ft_sort5(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}
