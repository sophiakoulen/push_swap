/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-utils-2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:19:13 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/12 10:19:16 by skoulen          ###   ########.fr       */
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
