/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:03:42 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/11 09:29:37 by skoulen          ###   ########.fr       */
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
	If the given string is a number, val is set to the integer value
	that the string represents.
	
	Return values are:
		0 in case of success
		-1 if str is not a valid integer
	
	Strings that represent values smaller than INT_MIN or
	greater than INT_MAX aren't valid integers.
	Strings that contain characters other than a leading minus or plus
	sign and digits aren't valid integers.
*/
int	strict_atoi(char *str, int *val)
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
	if (i == 0 || (str[i] && !ft_isspace(str[i])))
		return (-1);
	*val = nbr;
	return (0);
}
