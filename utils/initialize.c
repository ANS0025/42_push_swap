/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:13:36 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 16:35:34 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*initialize_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	initialize_stack(t_list *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}
