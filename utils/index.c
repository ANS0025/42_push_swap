/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:46 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 15:35:49 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*find_unindexed_min_node(t_list *stack)
{
	t_node	*current_node;
	t_node	*min_node;

	min_node = NULL;
	if (stack->head == NULL)
		return (NULL);
	current_node = stack->head;
	while (current_node != NULL && current_node->index != 0)
		current_node = current_node->next;
	if (current_node == NULL)
		return (NULL);
	min_node = current_node;
	while (current_node != NULL)
	{
		if (current_node->index == 0 && current_node->data < min_node->data)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

static void	set_index(t_list *stack)
{
	t_node	*current_node;
	t_node	*min_node;
	int		index;

	current_node = stack->head;
	index = 1;
	while (current_node != NULL)
	{
		min_node = find_unindexed_min_node(stack);
		if (min_node == NULL)
			break ;
		min_node->index = index++;
		current_node = current_node->next;
	}
}

static void	insert_tail(t_list *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
	stack->size++;
}

void	set_stack(t_list *stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_node	*node;

	i = 0;
	args = parse_args(argc, argv);
	while (args[i])
	{
		node = initialize_node(ft_atoi(args[i]));
		insert_tail(stack, node);
		i++;
	}
	set_index(stack);
	ft_free(args);
}
