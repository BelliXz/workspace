/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 08:24:33 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = num;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = ft_lstlast(*stack);
		last->next = node;
		node->prev = last;
	}
}

void	ft_init_stack(t_stack **a_stack, int ac, char **av)
{
	long	num;
	int		i;

	i = 0;
	while (av[i])
	{
		if (ft_check(av[i]))
		{
			if (ac == 2)
				ft_free(av - 1);
			ft_error(a_stack);
		}
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(a_stack);
		if (ft_check_dup(*a_stack, (int)num))
			ft_error(a_stack);
		ft_set_node(a_stack, (int)num);
		i++;
	}
}