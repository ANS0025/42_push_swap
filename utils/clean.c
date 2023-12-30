/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:11:10 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 00:11:24 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 2次元配列を解放
void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// stackの全てのノードを解放
void	free_stack(t_list *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->head;
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack);
}
