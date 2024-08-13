/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:46:06 by paradari          #+#    #+#             */
/*   Updated: 2024/02/17 15:46:08 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*new;
	t_stack	*tmp;

	if (!lst || !del || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst));
		if (!tmp)
			ft_lstclear(&tmp, del);
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
