/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:29:56 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 15:29:59 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_arrlen(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (0);
	while (array[i])
		i++;
	return (i);
}

static char	**merge_array(char **array, char **tmp)
{
	int		i;
	int		j;
	int		arr_len;
	int		tmp_len;
	char	**new_array;

	i = 0;
	j = 0;
	arr_len = ft_arrlen(array);
	tmp_len = ft_arrlen(tmp);
	new_array = (char **)malloc(sizeof(char *) * (arr_len + tmp_len + 1));
	if (!new_array)
		print_error();
	while (array && array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	while (tmp && tmp[j])
	{
		new_array[i + j] = ft_strdup(tmp[j]);
		j++;
	}
	new_array[i + j] = NULL;
	ft_free(array);
	return (new_array);
}

char	**parse_args(int argc, char **argv)
{
	int		i;
	char	**args;
	char	**tmp;

	i = 1;
	args = NULL;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		args = merge_array(args, tmp);
		ft_free(tmp);
		i++;
	}
	return (args);
}
