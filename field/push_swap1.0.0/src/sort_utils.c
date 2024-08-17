/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:31:35 by paradari          #+#    #+#             */
/*   Updated: 2024/08/15 18:31:37 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_pos(t_stack **stack_a)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->id == 0 || tmp->id == 1)
			return (pos);
		else
		{
			tmp = tmp->next;
			pos++;
		}
	}
	printf("%d\n", pos);
	return (pos);
}
