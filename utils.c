/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:32:12 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/06 15:13:15 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty(t_stack *s)
{
	return (!*s);
}

int	first(t_stack *s)
{
	return ((*s)->val);
}

int last(t_stack *s)
{
	return ((*s)->previous->val);
}

int	second(t_stack *s)
{
	return ((*s)->next->val);
}

void	print_stack(t_stack *a)
{
	t_list	*first;
	t_list	*iter;

	first = *a;
	iter = *a;
	if (!first)
	{
		ft_printf("(empty stack)\n");
		return ;
	}
	ft_printf("%d ", iter->val);
	iter = iter->next;
	while (iter != first)
	{
		ft_printf("%d ", iter->val);
		iter = iter->next;
	}
	ft_printf("\n");
}
