/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:40:42 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/02 14:42:45 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
