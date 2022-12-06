#include "push_swap.h"

int		*stack_to_array(t_stack a, int n)
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

int		get_median(t_stack a, int n, int *med)
{
	int *arr;

	if (n == 0)
		return (-1);
	arr = stack_to_array(a, n);
	if (!arr)
		return (-1);
	sort_int_tab(arr, n);
	if (n%2 == 0)
	{
		*med = arr[n/2 - 1];
	}
	else
		*med = arr[n/2];
	return (0);
}

void	partition(t_stack *a, t_stack *b, int n)
{
	int	pivot;
	int	first_greater;

	if (n == 0)
	{
		ft_printf("stack is empty\n");
		exit(1);
	}
	if (get_median(*a, n, &pivot) == -1)
	{
		ft_printf("computing median failed\n");
		exit(1);
	}

	first_greater = pivot;
	
	for(int i = 0; i < n; i++)
	{
		if (first(a) <= pivot)
		{
			pb(a, b);
		}
		else
		{
			if (first_greater == pivot)
				first_greater = first(a);
			ra(a, b);
		}
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

void	sort(t_stack *a, t_stack *b, int n)
{
	if (n < 2)
		return ;
	partition(a, b, n);

	sort(a, b, (n-1)/2);
	for (int i = 0; i < n/2; i++)
	{
		ra(a, b);
	}
	sort(a, b, n/2);
	for (int i = 0; i < (n/2); i++)
	{
		rra(a, b);
	}
}