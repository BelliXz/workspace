#include "push_swap.h"

void	showinput(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		printf("debug\n");
		printf("%d-----------------------%d\n", i, i);
		printf("Value : %d\nIndex : %d\n", stack->value, stack->index);
		stack = stack->next;
		i++;
	}
}