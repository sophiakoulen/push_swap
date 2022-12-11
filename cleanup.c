/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:21:29 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 13:35:24 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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
