/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:11:10 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 16:30:55 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// free two-dimensional array
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

// free all nodes in stack
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
