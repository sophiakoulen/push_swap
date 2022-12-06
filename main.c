/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:31:30 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/06 15:39:13 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		n;
	t_stack	a;
	t_stack	b;
	char	**strs;

	a = 0;
	b = 0;
	n = argc - 1;
	if (n == 1)
	{
		strs = ft_split(argv[1], ' ');
		parse_stack(strs, &a);
		free(strs);
	}
	else
	{
		parse_stack(argv + 1, &a);
	}
	bubble_sort(&a, &b);
	//sort(&a, &b, get_size(a));
	//print_stack(&a);
	cleanup_list(a);
	cleanup_list(b);
	return (0);
}
