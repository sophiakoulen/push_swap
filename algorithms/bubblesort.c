/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:29:35 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/02 14:29:58 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Performs a simple bubble sort on the A stack.
*/
void	bubble_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	sorted;
	int	i;

	n = get_size(*a);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < n)
		{
			if (i < n - 1)
			{
				if (first(a) > second(a))
				{
					sorted = 0;
					sa(a, b);
				}
			}
			ra(a, b);
			i++;
		}
	}
}
