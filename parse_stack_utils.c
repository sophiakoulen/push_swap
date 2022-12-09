/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:19:55 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/02 14:53:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, int n)
{
	int	i;
	int	sorted;
	int	tmp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < (n - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				sorted = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}

int	*copy_tab(int *tab, int n)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * n);
	if (!copy)
		return (0);
	i = 0;
	while (i < n)
	{
		copy[i] = tab[i];
		i++;
	}
	return (copy);
}

/* 
	returns 0 if array contains no duplicates,
	returns -1 if there are duplicates or malloc failure
*/
int	check_duplicates(int *tab, int n)
{
	int	*copy;
	int	i;

	copy = copy_tab(tab, n);
	if (!copy)
	{
		return (-1);
	}
	sort_int_tab(copy, n);
	i = 0;
	while (i < (n - 1))
	{
		if (copy[i] == copy[i + 1])
		{
			free(copy);
			return (-1);
		}
		i++;
	}
	free(copy);
	return (0);
}

/*
	strs is a null-terminated array of C-strings.
	returns 0 if success
	returns -1 if failure
*/
int	get_int_tab(char **strs, int **tab, int *n)
{
	int	i;
	int	res;

	*n = 0;
	while (strs[*n])
		(*n)++;
	*tab = malloc(sizeof(int) * *n);
	if (!*tab)
		return (0);
	i = 0;
	while (i < *n)
	{
		res = strict_atoi(strs[i], *tab + i);
		if (res == -1)
		{
			free(*tab);
			return (-1);
		}
		i++;
	}
	return (0);
}

/*
Return values:
	0 in case of SUCCESS
	1 in case of MALLOC FAILURE
*/
int	normalize(int *tab, int n)
{
	int	*copy;
	int	i;
	int	j;

	copy = copy_tab(tab, n);
	if (!tab)
		return (-1);
	sort_int_tab(copy, n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (tab[i] == copy[j])
			{
				tab[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
	return (0);
}
