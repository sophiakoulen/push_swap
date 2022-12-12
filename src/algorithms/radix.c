/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:49:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 11:49:46 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b, int n)
{
	int	mask;
	int	i;

	mask = 1;
	while (mask <= (n - 1))
	{
		i = 0;
		while (i < n)
		{
			if (!(first(a) & mask))
				pb(a, b);
			else
				ra(a, b);
			i++;
		}
		while (!empty(b))
		{
			pa(a, b);
		}
		mask = mask << 1;
	}
}
