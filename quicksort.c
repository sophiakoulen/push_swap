#include "push_swap.h"

/*
	Returns the minimum (if flag_min is true, else the maximum)
	of the top n elements of the stack. 
*/
int	get_min_or_max(t_stack s, int n, int flag_min)
{
	int	res;
	int i;

	res = s->val;
	s = s->next;
	i = 1;
	while (i < n)
	{
		if ((s->val < res) == flag_min)
			res = s->val;
		s = s->next;
		i++;
	}
	return (res);
}

/*
	Returns the median of the first n elements of the stack.
*/
int	get_median(t_stack a, int n)
{
	int	min;
	int	max;

	min = get_min_or_max(a, n, 1);
	max = get_min_or_max(a, n, 0);
	//ft_printf("min: %d, max: %d\n", min, max);
	return (min + (max - min)/2);
}

void	partition(t_stack *a, t_stack *b, int n)
{
	int	pivot;
	int	first_greater;
	int	i;

	pivot = get_median(*a, n);
	//print_stack(a);
	//ft_printf("partionning %d items with pivot: %d\n", n, pivot);
	first_greater = pivot;
	i = 0;
	while (i < n)
	{
		if (first(a) <= pivot)
			pb(a, b);
		else
		{
			if (first_greater == pivot)
				first_greater = first(a);
			ra(a, b);
		}
		i++;
	}
	while (first(a) != first_greater)
	{
		rra(a, b);
	}
	/*
	ft_printf("stack a: ");
	print_stack(a);
	ft_printf("stack b: ");
	print_stack(b);
	*/
	while (first(b) != pivot)
	{
		rb(a, b);
	}
	while (!empty(b))
    {
		pa(a, b);
	}
}

void	partition2(t_stack *a, t_stack *b, int n)
{
	int	pivot;

	pivot = get_median(*a, n);
	for(int i = 0; i < n - 1; i++)
	{

		if (first(a) == pivot)
		{
			sa(a, b);
		}
		if (first(a) < pivot)
		{
			pb(a, b);
			rb(a, b);
		}
		else if (first(a) > pivot)
		{
			pb(a, b);
		}
	}
	
	for(int i = 0; i < (n - 1); i++)
	{
		pa(a, b);
		if (first(a) > pivot)
			sa(a, b);
	}
}

void	quick_sort(t_stack *a, t_stack *b, int n)
{
	if (n < 2)
	{
		return ;
	}
	
	if (n == 2)
	{
		sort2(a, b);
		return ;
	}

	if (n == 3)
	{
		sort3_top(a, b);
		return ;
	}
	
	partition(a, b, n);

	quick_sort(a, b, n / 2);

	for (int i = 0; i < n / 2; i++)
	{
        ra(a, b);
    }

	quick_sort(a, b, n - n / 2);
	
	for (int i = 0; i < n / 2; i++)
	{
		rra(a, b);
	}
}
