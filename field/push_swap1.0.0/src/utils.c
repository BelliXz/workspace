t_stack	*ft_stknew(int value)
{
	t_stack	*new;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stklast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
		tmp = tmp->next;
	return (tmp);
}

void	ft_stkadd_back(t_stack **stack, t_stack *to_add)
{
	t_stack	*tmp;
	
	if (*stack)
	{
		tmp = ft_stklast(*stack);
		tmp->next = to_add;
		to_add->next = NULL;//
	}
	else
	{
		*stack = to_add;
		(*stack)->next = NULL;//
	}
}

size_t	ft_stksize(t_stack *stack)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

size_t	ft_find_max(t_stack **stack)
{
	t_stack	*node;
	size_t	max;
	size_t	max_bit;

	node = *stack;
	max = node->index;
	max_bit = 0;
	while (node)
	{
		if (node->index > max)
			max_bit = node->index;
		node = node->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}