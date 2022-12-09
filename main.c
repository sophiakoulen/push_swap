/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:31:30 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/08 12:49:00 by skoulen          ###   ########.fr       */
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
	
	//print_stack(&a);
	
	n = get_size(a);
	if (n == 3)
		sort3(&a, &b);
	else if (n == 5)
		sort5(&a, &b);
	else
		quick_sort(&a, &b, n);
		
	//print_stack(&a);
	
	cleanup_list(a);
	cleanup_list(b);
	return (0);
}
