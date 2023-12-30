/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:42:00 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 13:42:04 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

long long	custom_atoi(const char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (is_whitespace(*str))
		str++;
	sign = get_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		if (num > LONG_MAX / 10
			|| (num == LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10))
		{
			if (sign == -1)
				return (LONG_MIN);
			else
				return (LONG_MAX);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
