/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:51:48 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 11:52:15 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
