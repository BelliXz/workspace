void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_first;
	size_t	i;
	size_t	stack_size;
	size_t	max;
	size_t	j;

	a_first = *stack_a;
	i = 0;
	stack_size = ft_stksize(*stack_a);
	max = ft_find_max(stack_a);
	while (i < max)
	{
		j = 0;
		while (j < stack_size)
		{
			a_first = *stack_a;
			if (((a_first->index >> i) & 1) == 1)
				rotate(stack_a, "ra");
			else
				push(stack_a, stack_b, "pb");
		}
		while (ft_stksize(stack_b) != 0)
			push(stack_b, stack_a, "pa");
		i++;
	}
}

void	ft_sort3(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (first->index > second->index && first->index < third->index)
		swap(stack, "sa");
	else if (first->index > second->index && second->index > third->index)
	{
		rotate(stack, "ra");
		swap(stack, "sb");
	}
	else if (first->index > second->index && second->index < third->index
			&& first->index > third->index)
			rotate(stack, "ra");
	else if (first->index < second->index && second->index > third->index
			&& first->index < third->index)
	{
			swap(stack, "sa");
			rotate(stack, "ra");
	}
	else if (first->index < second->index && second->index > third->index
			&& first->index > third->index)
			rev_rotate(stack, "rra");
}

void	ft_sort_2_3(t_stack **stack)
{
	if (ft_stksize(*stack) == 2)
		swap(stack, "sa");
	else
		ft_sort3(stack);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stksize(*stack_a) <= 3)
		ft_sort_2_3(stack_a);
	else
		ft_radix_sort(stack_a, stack_b);
}