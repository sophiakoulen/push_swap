#include "push_swap.h"

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
		rra(a, b);
		sa(a, b);
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
	if (first(a) > second(a) && first(a) > third(a))
	{
		sa(a, b);
		pb(a, b);
		if (first(a) > second(a))
			sa(a, b);
		pa(a, b);
		if (first(a) > second(a))
			sa(a, b);
	}
	else if (first(a) < second(a) && first(a) < third(a))
	{
		pb(a, b);
		sa(a, b);
		pa(a, b);
	}
	else
	{
		if (second(a) < third(a))
			sa(a, b);
		else
		{
			pb(a, b);
			sa(a, b);
			pa(a, b);
			sa(a, b);
		}
	}
}

void	sort5(t_stack *a, t_stack *b)
{
	int	pivot;
	int	i;

	pivot = get_median(*a, 5);
	i = 0;
	while (i < 5)
	{
		if (first(a) < pivot)
			pb(a, b);
		else
			ra(a, b);
		i++;
	}
	if (first(b) < second(b))
		sb(a, b);
	sort3(a, b);
	pa(a, b);
	pa(a, b);
}