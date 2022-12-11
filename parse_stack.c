/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:16:34 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 11:38:01 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_stack(int *tab, int n, t_stack *s)
{
	int		i;
	t_list	*new_node;

	i = 0;
	while (i < n)
	{	
		new_node = factory(tab[n - i - 1]);
		if (!new_node)
		{
			return (-1);
		}
		push(s, new_node);
		i++;
	}
	return (0);
}

static void	error_handler(int *tab)
{
	ft_dprintf(2, "Error\n");
	free(tab);
	exit(1);
}

static void	parse_stack(char **strs, t_stack *s)
{
	int	*tab;
	int	n;

	tab = 0;
	if (get_int_tab(strs, &tab, &n) == -1)
		error_handler(tab);
	if (check_duplicates(tab, n) == -1)
		error_handler(tab);
	if (normalize(tab, n) == -1)
		error_handler(tab);
	if (create_stack(tab, n, s) == -1)
		error_handler(tab);
	free(tab);
}

void	parse_args(int n, char **argv, t_stack *a, t_stack *b)
{
	char	**strs;

	*a = 0;
	*b = 0;
	if (n == 1)
	{
		strs = ft_split(argv[1], ' ');
		parse_stack(strs, a);
		free(strs);
	}
	else
	{
		parse_stack(argv + 1, a);
	}
}
