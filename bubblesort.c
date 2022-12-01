#include "push_swap.h"

void	bubble_sort(t_stack *a, t_stack *b)
{
	int	n;
	int sorted;
	int	i;

	n = get_size(*a);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < n)
		{
			//print_stack(a);
			if (i < n - 1)
			{
				if (first(a) > second(a))
				{
					sorted = 0;
					sa(a, b);
					//print_stack(a);
				}
			}
			ra(a, b);
			i++;
		}
	}
}