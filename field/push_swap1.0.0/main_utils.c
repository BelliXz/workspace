/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:44 by paradari          #+#    #+#             */
/*   Updated: 2024/08/13 15:38:46 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack *stack)
{
	t_stack	*first;
	t_stack	*tmp;

	first = stack;
	tmp = stack->next;
	while (stack)
	{
		while (tmp)
		{
			if (stack->value > tmp->value)
				stack->index++;
			tmp = tmp->next;
		}
		tmp = first;
		stack = stack->next;
	}
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

void	ft_clearstack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
