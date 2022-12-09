/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:16:34 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/02 14:44:16 by skoulen          ###   ########.fr       */
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

void	parse_stack(char **strs, t_stack *s)
{
	int	*tab;
	int	n;
	int	err;

	err = get_int_tab(strs, &tab, &n);
	if (err == -1)
	{
		ft_dprintf(2, "Error\n");
		exit(1);
	}
	err = check_duplicates(tab, n);
	if (err == -1)
	{
		ft_dprintf(2, "Error\n");
		free(tab);
		exit(1);
	}
	err = normalize(tab, n);
	if (err == -1)
	{
		ft_dprintf(2, "Error\n");
		free(tab);
		exit(1);
	}
	err = create_stack(tab, n, s);
	if (err == -1)
	{
		ft_dprintf(2, "Error\n");
		free(tab);
		exit(1);
	}
	free(tab);
}
