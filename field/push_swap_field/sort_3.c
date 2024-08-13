/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:55:09 by paradari          #+#    #+#             */
/*   Updated: 2024/07/29 10:13:04 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **a_stack)
{
	t_stack	*max;

	max = ft_find_max(*a_stack);
	if (max == *a_stack)
		rotate(a_stack);
	else if (max == (*a_stack)->next)
		rev_rotate(a_stack);
	if ((*a_stack)->nbr > (*a)->next->nbr)
		swap(a);
}