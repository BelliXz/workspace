/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/15 12:55:12 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issort(t_stack *a)
{
	t_stack	*tmp;

	tmp = a->next;
	while (a->value < tmp->value && tmp)
	{
		a = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	else
		return (0);
}

void	ft_add_to_stack(char *nbr, t_stack **a)
{
	t_stack	*tmp;
	long	num;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	num = ft_atoi(nbr);
	if (num > INT_MAX || num < INT_MIN)
	{
		free (tmp);
		return ;
	}
	tmp->value = (int)num;
	tmp->index = 0;
	ft_lstadd_back(a, tmp);
}

size_t	ft_av_check(char *av)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (av[i] < '0' && av[i] > '9' && av[i])
			return (0);
		else
		{
			while (av[i] != ' ' && av[i] >= '0' && av[i] <= '9' && av[i])
				i++;
			count++;
		}
	}
	return (count);
}

int	ft_init_stack(int ac, char **av, t_stack *a)
{
	int		i;
	int		j;
	char	**nbr;

	i = 1;
	while (i < ac)
	{
		if (!ft_av_check(av[i]))
		{
			ft_free_array(nbr);
			return (0);
		}
		nbr = ft_split(av[i], ' ');
		j = 0;
		while (nbr[j])
			ft_add_to_stack(nbr[j++], &a);
		ft_free_array (nbr);
		i++;
	}
	ft_index(a);
	a = first;
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	if (ac <= 1)
	{
		ft_putstr_fd("Input must be more than 1 arg\n", 1);
		return (1);
	}
	a = NULL;
	b = NULL;
	if (ft_init_stack(ac, av, a))
	{
		showinput(a);
		// if (ft_issort(a))
		// {
		// 	if (ft_lstsize(a) <= 3)
		// 		ft_sort_2_3(&a);
		// 	else
		// 		ft_sort(&a, &b);
		// }
	}
	ft_clearstack(a);
	ft_clearstack(b);
	return (0);
}
