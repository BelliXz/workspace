#include "../push_swap.h"

void	swap(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*tmp;
	int		value;
	int		index;

	if (ft_stksize(*stack) < 2)
		return ;
	first = *stack;
	tmp = first->next;
	value = tmp->value;
	index = tmp->index;
	tmp->value = first->value;
	tmp->index = first->index;
	first->value = value;
	first->index = index;
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	push(t_stack **from, t_stack **to, char *op)
{
	t_stack	*new_from;
	t_stack	*new_to;
	t_stack	*tmp;

	new_from = *from;
	new_to = *to;
	tmp = new_from;
	new_from = new_from->next;
	*from = new_from;
	if (!new_to)
	{
		new_to = tmp;
		new_to->next = NULL;
		*to = new_to;
	}
	else
	{
		tmp->next = new_to;
		*to = tmp;
	}
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	rotate(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = ft_stklast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	rev_rotate(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*last;
	first = *stack;
	last = ft_stklast(*stack);
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break;
		}
		first = first->next;
	}
	last->next = *stack;
	*stack = last;
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}