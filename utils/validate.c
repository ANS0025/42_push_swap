/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:49:57 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 15:55:26 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
		if (num[1] == '\0')
			return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	has_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_args(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = parse_args(argc, argv);
	if (args[0] == NULL || has_duplicate(args))
		print_error();
	while (args[i])
	{
		if (!isnum(args[i]))
			print_error();
		if (custom_atoi(args[i]) > INT_MAX || custom_atoi(args[i]) < INT_MIN)
			print_error();
		i++;
	}
	ft_free(args);
}
