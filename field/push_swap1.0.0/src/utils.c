/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:40:54 by paradari          #+#    #+#             */
/*   Updated: 2024/08/15 14:40:55 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->id = 0;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stklast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_stkadd_back(t_stack **stack, t_stack *to_add)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = ft_stklast(*stack);
		tmp->next = to_add;
		to_add->next = NULL;
	}
	else
	{
		*stack = to_add;
		(*stack)->next = NULL;
	}
}

int	ft_stksize(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_find_max(t_stack **stack)
{
	t_stack	*node;
	int		max;
	int		max_bit;

	node = *stack;
	max = node->id;
	max_bit = 0;
	while (node)
	{
		if (node->id > max)
			max = node->id;
		node = node->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}
