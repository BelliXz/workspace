#include "../push_swap.h"

void	ft_add_to_stack(char *nbr, t_stack **stack)
{
	t_stack *tmp;

	tmp = ft_stknew(ft_atoi(nbr));
	ft_stkadd_back(stack, tmp);
}

int	ft_is_sort(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_index(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp1;
	t_stack	*tmp2;

	first = *stack;
	tmp1 = first;
	tmp2	= first;
	while (tmp1)
	{
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				tmp1->index++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = first; 
	}
}

int	ft_init_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*tmp;
	char	**nbr;
	size_t	i;
	size_t	j;

	i = 1;
	while (i < ac)
	{
		nbr = ft_split(av[i], ' ');
		if (ft_check_input(nbr, stack))
		{
			ft_free(nbr);
			return (1);
		}
		j = 0;
		while (nbr[j])
			ft_add_to_stack(nbr[j++], stack);
		ft_free(nbr);
		i++;
	}
	ft_index(stack);
	return (0);
}

int	main(int ac, **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac < 2)
	{
		ft_putstr_fd("Input must be more than 1 args\n", 1);
		return (1);
	}
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	if (ft_init_stack(stack_a, ac, av) == 0)
	{
		if (ft_is_sort(stack_a) == 0)
			ft_sort(stack_a, stack_b);
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}