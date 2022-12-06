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