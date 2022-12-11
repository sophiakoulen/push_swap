/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:31:30 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 15:06:39 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	sort(t_stack *a, t_stack *b)
{
	int	n;

	n = get_size(*a);
	if (!n_sorted(*a, n))
	{
		if (n == 2)
		{
			sort2(a, b);
		}
		else if (n == 3)
		{
			sort3(a, b);
		}
		else if (n == 5)
		{
			sort5(a, b);
		}
		else
		{
			quick_sort(a, b, n);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	parse_args(argc - 1, argv, &a, &b);
	sort(&a, &b);
	cleanup_list(a);
	cleanup_list(b);
	return (0);
}
