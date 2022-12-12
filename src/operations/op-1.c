/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:33:15 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/02 14:42:34 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
