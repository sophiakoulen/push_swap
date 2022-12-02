/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:30:32 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/02 14:30:37 by skoulen          ###   ########.fr       */
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

void	cleanup_list(t_list *node)
{
	t_list	*last;
	t_list	*next;

	if (!node)
		return ;
	if (node->next == node)
	{
		free(node);
		return ;
	}
	last = node->previous;
	while (node != last)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(last);
}
