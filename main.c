/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:31:30 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 11:45:49 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		n;
	t_stack	a;
	t_stack	b;

	parse_args(argc - 1, argv, &a, &b);
	n = get_size(a);
	if (n == 3)
	{
		sort3(&a, &b);
	}
	else if (n == 5)
	{
		sort5(&a, &b);
	}
	else
	{
		quick_sort(&a, &b, n);
	}
	cleanup_list(a);
	cleanup_list(b);
	return (0);
}
