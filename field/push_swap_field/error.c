/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 08:24:13 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_error(t_stack **a)
{
	ft_free_stack(a);
	ft_putstr_fd("Error\n", 1);
	exit (1);
}

int	ft_check(char *str)
{
	if (!(ft_isdigit(*str) || *str == '+' || *str == '-'))
		return (1);
	if (!(ft_isdigit(str[1])) && (*str == '+' || *str == '-'))
		return (1);
	while (*(++str))
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	ft_check_dup(t_stack *stack, int num)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}