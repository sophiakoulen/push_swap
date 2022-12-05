/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_careful.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:03:42 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/05 10:52:40 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns -1 in case f underflow/overflow, 0 else */
static int	add_digit(int *n, int digit, int sign)
{
	int	tmp;

	tmp = *n * 10;
	if (*n != 0 && tmp / 10 != *n)
	{
		return (-1);
	}
	*n = tmp;
	if ((sign == 1 && *n > INT_MAX - digit)
		|| (sign == -1 && *n < INT_MIN + digit))
		return (-1);
	*n += digit * sign;
	return (0);
}

/*
	Returns -1 in case of underflow/overflow, 0 else.
*/
int	atoi_careful(char *str, int *val)
{
	int	sign;
	int	nbr;
	int	i;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		if (add_digit(&nbr, str[i] - '0', sign) == -1)
			return (-1);
		i++;
	}
	*val = nbr;
	return (0);
}
