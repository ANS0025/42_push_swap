/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:13:36 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 00:14:23 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ノードの生成と初期化
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

// スタックの初期化
void	initialize_stack(t_list *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}
