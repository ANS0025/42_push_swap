/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:44:35 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/29 23:44:37 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*find_max_node(t_list *stack)
{
	t_node	*current_node;
	t_node	*max_node;

	if (stack->head == NULL)
		return (NULL);
	current_node = stack->head;
	max_node = current_node;
	while (current_node != NULL)
	{
		if (current_node->data > max_node->data)
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}

void	sort_three_elements(t_list *stack)
{
	t_node	*highest;

	highest = find_max_node(stack);
	while (!is_sorted(stack))
	{
		if (stack->head->index == highest->index)
			ra(stack);
		else if(stack->head->next->index == highest->index)
			rra(stack);
		else if(stack->tail->index == highest->index)
			sa(stack);
	}
}
