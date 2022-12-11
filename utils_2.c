/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:30:32 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 14:04:41 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*factory(int val)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->val = val;
	node->next = 0;
	node->previous = 0;
	return (node);
}

int	get_size(t_list *node)
{
	t_list	*first;
	int		i;

	first = node;
	i = 1;
	if (!first)
		return (0);
	node = node->next;
	while (node != first)
	{
		i++;
		node = node->next;
	}
	return (i);
}

/*
	Checks whether the first n elements of the array are sorted.
*/
int	n_sorted(t_stack s, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (s->val > s->next->val)
			return (0);
		s = s->next;
		i++;
	}
	return (1);
}
