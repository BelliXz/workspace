/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 08:38:35 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max;
	int		num;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			num = stack->nbr;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}