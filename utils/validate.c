/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:09:50 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 03:15:43 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
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

static int	ft_arrlen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

// 引数が重複していないかどうかを判定
static int	has_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// 引数が正しいかどうかを判定
void	validate_args(int argc, char **argv)
{
	int		i;
	int		args_len;
	char	**args;	

	i = 1;
	args = argv;
	args_len = argc;
	if (argc == 2)
	{
		i = 0;
		args = ft_split(argv[1], ' ');
		args_len = ft_arrlen(args);
	}
	if (args[0] == NULL || has_duplicate(args_len, args))
		print_error();
	while (args[i])
	{
		if (!isnum(args[i]))
			print_error();
		if (custom_atoi(args[i]) > INT_MAX || custom_atoi(args[i]) < INT_MIN)
			print_error();
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
