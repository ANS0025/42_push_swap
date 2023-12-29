/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:09:50 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 00:27:07 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// スタックがソート済みかどうかを判定
int	is_sorted(t_list *stack)
{
	t_node	*node;

	node = stack->head;
	while (node->next != NULL)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

static int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
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

// 引数が重複していないかどうかを判定
int	has_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
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
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (has_duplicate(argc, args))
		print_error();
	while (args[i])
	{
		if (!isnum(args[i]))
			print_error();
		if (ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN)
			print_error();
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
