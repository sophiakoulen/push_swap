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
		ft_printf("pivot nr: %d\n", n/2 - 1);
		*med = arr[n/2 - 1];
	}
	else
		*med = arr[(n-1)/2];
	return (0);
}

void	partition(t_stack *a, t_stack *b, int n)
{
	int	pivot;
	int	first_greater;

	ft_printf("partitionning %d\n", n);

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
	ft_printf("pivot: %d\n", pivot);
	first_greater = pivot;
	for(int i = 0; i < n; i++)
	{
		if (first(a) <= pivot)
			pb(a, b);
		else
		{
			if (first_greater == pivot)
				first_greater = first(a);
			ra(a, b);
		}
	}
	print_stack(a);
	print_stack(b);
	while (first(a) != first_greater)
	{
		rra(a, b);
	}
	print_stack(a);
	print_stack(b);
	while (!empty(b))
	{
		pa(a, b);
	}
	print_stack(a);
	print_stack(b);
}

void	sort(t_stack *a, t_stack *b, int n)
{
	if (n < 2)
		return ;
	partition(a, b, n);
	//ft_printf("after partition:\n");
	//print_stack(a);
	sort(a, b, n/2);
	/*ft_printf("after sorting top %d\n", n/2);
	print_stack(a);*/
	for (int i = 0; i < n/2; i++)
	{
		ra(a, b);
	}
	/*ft_printf("after rotating:\n");
	print_stack(a);*/
	sort(a, b, n/2 + n%2);
	/*ft_printf("after sorting bottom (now top)\n");
	print_stack(a);*/
	for (int i = 0; i < (n/2); i++)
	{
		rra(a, b);
	}
	/*ft_printf("after rotating\n");
	print_stack(a);*/
	//ft_printf("\n");
}