/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:40:00 by paradari          #+#    #+#             */
/*   Updated: 2024/08/15 14:40:02 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *stack;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}
