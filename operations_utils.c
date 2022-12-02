/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:34:37 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/02 15:02:35 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *s)
{
	if (!*s)
	{
		return ;
	}
	*s = (*s)->previous;
}

void	rotate(t_stack *s)
{
	if (!*s)
	{
		return ;
	}
	*s = (*s)->next;
}

void	swap(t_stack *s)
{
	int	tmp;
	int	*first;
	int	*second;

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

t_list	*pop(t_stack *s)
{
	t_list	*ret;
	t_list	*prev;
	t_list	*next;

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
