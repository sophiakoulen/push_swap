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
	return (min + (max - min)/2);
}

/*
	Partitionning algorithm 1

	Partition the n top elements of stack a:
	Choose a pivot item and make sure anything smaller than the pivot
	gets on top of it and anything greater under it.

	To achieve this, of the n elements, put the smaller or equal elements on stack b,
	and the greater elements at the bottom of stack a.

	When we've done it for the first n elements, we need to put the greater elements
	on top of the stack again.

	Now, we need to make sure the pivot element gets on top of stack b by rotating it.
	Then, put all elements of stack b back on stack a.
*/
void	partition(t_stack *a, t_stack *b, int n)
{
	int	pivot;
	int	first_greater;
	int	i;

	pivot = get_median(*a, n);
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
	while (first(b) != pivot)
	{
		rb(a, b);
	}
	while (!empty(b))
    {
		pa(a, b);
	}
}

/*
	Sort the top n elements of stack a:
	Partition the first n elements.
	Sort the first halve.
	Rotate the stack to put the first halve beneath.
	Sort the second halve.
	Rotate the stack to put the first halve on top again.
*/
void	quick_sort(t_stack *a, t_stack *b, int n)
{
	int	i;

	if (n == 2)
	{
		sort2(a, b);
	}
	else if (n == 3)
	{
		sort3_top(a, b);
	}
	else if (n > 3)
	{
		partition(a, b, n);
		quick_sort(a, b, n / 2);
		i = 0;
		while (i < n / 2)
		{
        	ra(a, b);
			i++;
    	}
		quick_sort(a, b, n - n / 2);
		i = 0;
		while (i < n / 2)
		{
			rra(a, b);
			i++;
		}
	}
}
