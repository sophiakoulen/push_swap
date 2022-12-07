#include "push_swap.h"

static int	*stack_to_array(t_stack a, int n)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * n);
	if (!arr)
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		arr[i] = a->val;
		a = a->next;
		i++;
	}
	return (arr);
}

static int	get_median(t_stack a, int n, int *med)
{
	int *arr;

	if (n == 0)
		return (-1);
	arr = stack_to_array(a, n);
	if (!arr)
		return (-1);
	sort_int_tab(arr, n);
	if (n%2 == 0)
		*med = arr[n/2 - 1];
	else
		*med = arr[n/2];
	return (0);
}

void	sort2(t_stack *a, t_stack *b)
{
	if (first(a) < second(a))
	{
		return ;
	}
	sa(a, b);
}

void	sort3(t_stack *a, t_stack *b)
{
	if (first(a) < second(a) && second(a) < third(a))
		return ;
	if (first(a) < second(a) && first(a) < third(a))
	{
		pb(a, b);
		sa(a, b);
		pa(a, b);
		return ;
	}
	else if (first(a) > second(a) && first(a) > third(a))
	{
		ra(a, b);
		if (first(a) > second(a))
			sa(a, b);
	}
	else
	{
		if (second(a) > third(a))
			rra(a, b);
		else
			sa(a, b);
	}
}

void	sort3_top(t_stack *a, t_stack *b)
{
	if (first(a) < second(a) && second(a) < third(a))
		return ;
	if (first(a) < second(a) && first(a) < third(a))
	{
		pb(a, b);
		sa(a, b);
		pa(a, b);
		return ;
	}
	else if (second(a) < first(a) && second(a) < th)
	{
		ra(a, b);
		if (first(a) > second(a))
			sa(a, b);
	}
	else
	{
		if (second(a) > third(a))
			rra(a, b);
		else
			sa(a, b);
	}
}

static void	partition(t_stack *a, t_stack *b, int n)
{
	int	pivot;
	int	first_greater;
	int	i;

	if (get_median(*a, n, &pivot) == -1)
	{
		ft_printf("malloc failure\n");
		exit(1);
	}
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
		rra(a, b);
	while (first(b) != pivot)
		rb(a, b);
	while (!empty(b))
        pa(a, b);
	//print_stack(a);
}

void	quick_sort(t_stack *a, t_stack *b, int n)
{
	if (n < 2)
		return ;

	if (n == 2)
	{
		sort2(a, b);
		return ;
	}
	
	partition(a, b, n);

	quick_sort(a, b, (n-1)/2);

	for (int i = 0; i < (n-1)/2 + 1; i++)
	{
        ra(a, b);
    }

	quick_sort(a, b, n/2);
	
	for (int i = 0; i < (n-1)/2 + 1; i++)
	{
		rra(a, b);
	}
}
