/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:39:53 by paradari          #+#    #+#             */
/*   Updated: 2024/08/15 14:39:55 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_num(char	**nbr)
{
	int	i;
	int	j;

	i = 0;
	while (nbr[i])
	{
		j = 0;
		if (nbr[i][j] == '-' || nbr[i][j] == '+')
			j++;
		while (nbr[i][j])
		{
			if (nbr[i][j] < '0' || nbr[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_dup(int num, t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int	ft_check_input(char **nbr, t_stack **stack)
{
	int		i;
	long	num;

	i = 0;
	if (ft_is_num(nbr))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	num = ft_atoi(nbr[i]);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (ft_check_dup(num, stack))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	return (0);
}
