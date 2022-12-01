#include "push_swap.h"

int	empty(t_stack *s)
{
	return (!!*s);
}

int	first(t_stack *s)
{
	return ((*s)->val);
}

int second(t_stack *s)
{
	return ((*s)->next->val);
}

void	print_stack(t_stack *a)
{
	t_list *first;

	first = *a;
	if (!first)
	{
		ft_printf("(empty stack)\n");
	}
	ft_printf("%d ", (*a)->val);
	*a = (*a)->next;
	while (*a != first)
	{
		ft_printf("%d ", (*a)->val);
		*a = (*a)->next;
	}
	ft_printf("\n");
}