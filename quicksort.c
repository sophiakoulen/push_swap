#include "push_swap.h"

void	partition(t_stack *a, t_stack *b)
{
	int n;

	(void)b;
	n = get_size(*a);
	int pivot = first(a);
	ft_printf("pivot: %d\n", pivot);
}