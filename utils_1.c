/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:32:12 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 11:52:06 by skoulen          ###   ########.fr       */
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

int	last(t_stack *s)
{
	return ((*s)->previous->val);
}

int	second(t_stack *s)
{
	return ((*s)->next->val);
}

int	third(t_stack *s)
{
	return ((*s)->next->next->val);
}
