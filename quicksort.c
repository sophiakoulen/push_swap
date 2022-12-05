#include "push_swap.h"

int		*stack_to_array(t_stack a)
{
	int	n;
	int	*arr;
	int	i;

	n = get_size(a);
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

int		get_median(t_stack a, int *med)
{
	int n;
	int *arr;

	n = get_size(a);
	if (n == 0)
		return (-1);
	arr = stack_to_array(a);
	if (!arr)
		return (-1);
	sort_int_tab(arr, n);
	*med = arr[(n-1) / 2];
	return (0);
}

void	partition(t_stack *a, t_stack *b)
{
	int n;
	int	pivot;

	n = get_size(*a);
	if (n == 0)
	{
		ft_printf("stack is empty\n");
		exit(1);
	}
	if (get_median(*a, &pivot) == -1)
	{
		ft_printf("computing median failed\n");
		exit(1);
	}
	ft_printf("pivot: %d\n", pivot);
	for(int i = 0; i < n; i++)
	{
		if (first(a) <= pivot)
			pb(a, b);
		else
			ra(a, b);
	}
	while (!empty(b))
	{
		pa(a, b);
	}
	print_stack(a);
	print_stack(b);
}