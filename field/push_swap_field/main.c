/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 08:30:26 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

int	ft_issort(t_stack *a_stack)
{
	while (a_stack->next)
	{
		if (stack-nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	check_n_sort(t_stack *a_stack)
{
	if (!ft_issort(a))
	{
		s_len = ft_lstsize(a);
		if (s_len == 2)
			swap(&a);
		else if (s_len == 3)
			ft_sort_3(&a);
		else
			ft_sort(&a, &b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**temp;
	int		s_len;

	temp = av;
	a_stack = NULL;
	b_stack = NULL;
	if (ac == 1 || (ac == 2 && !ac[1][0]))
		return (1);
	else if (ac == 2)
		temp = ft_split(av[1], ' ');
	ft_init_stack(&a, ac, temp);
	ft_free_stack(&a);
	if (ac == 2)
		ft_free(temp);
	return (0);
}