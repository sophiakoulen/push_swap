#include "push_swap.h"

/*
	index 0 is bottom of the stack,
	index n - 1 is top of the stack!!!
*/

/* static helper functions here */

static void	rev_rotate(t_stack *s)
{
	if (!*s) //not empty?
	{
		return ;
	}
	*s = (*s)->previous;
}

static void	rotate(t_stack *s)
{
	if (!*s) //not empty?
	{
		return ;
	}
	*s = (*s)->next;
}

static void	swap(t_stack *s)
{
	int tmp;
	int *first;
	int *second;

	if (!*s || ((*s)->next == *s))
	{
		return ;
	}
	first = &((*s)->val);
	second = &((*s)->next->val);
	tmp = *first;
	*first = *second;
	*second = tmp;
}

static t_list *pop(t_stack *s)
{
	t_list *ret;
	t_list *prev;
	t_list *next;

	ret = *s;
	ret->previous = 0;
	ret->next = 0;
	if ((*s)->next != *s)
	{
		prev = (*s)->previous;
		next = (*s)->next;
		prev->next = next;
		next->previous = prev;
	}
	else
	{
		*s = 0;
	}
	return (ret);
}

void	push(t_stack *s, t_list *node)
{
	t_list	*first;
	t_list	*last;

	if (!*s)
	{
		*s = node;
		(*s)->previous = *s;
		(*s)->next = *s;
	}
	else
	{
		first = *s;
		last = (*s)->previous;
		node->next = first;
		node->previous = last;
		first->previous = node;
		last->next = node;
		*s = node;
	}
}

/* operations here */

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *a, t_stack *b)
{
	(void)a;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
	ft_printf("rrr\n");
}

void	rra(t_stack *a, t_stack *b)
{
	(void)b;
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *a, t_stack *b)
{
	(void)a;
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
	ft_printf("rrr\n");
}


void	pa(t_stack *a, t_stack *b)
{
	push(a, pop(b));
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, pop(a));
	ft_printf("pb\n");
}

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *a, t_stack *b)
{
	(void)a;
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
	ft_printf("ss\n");
}