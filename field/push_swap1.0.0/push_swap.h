/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:01:00 by paradari          #+#    #+#             */
/*   Updated: 2024/08/08 16:15:59 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_init_stack(int ac, char **av, t_stack *a);
size_t	ft_av_check(char *av);
void	ft_add_to_stack(char *nbr, t_stack **a);
int		ft_issort(t_stack *a);
void	ft_index(t_stack *stack);
void	ft_free_array(char **array);
void	ft_clearstack(t_stack *stack);

void	showinput(t_stack *stack);
// ft_sort_2_3();
// ft_sort();

#endif
