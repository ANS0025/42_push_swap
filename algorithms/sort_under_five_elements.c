/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:44:45 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/29 23:44:47 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*find_min_node(t_list *stack)
{
	t_node	*current_node;
	t_node	*min_node;

	if (stack->head == NULL)
		return (NULL);
	current_node = stack->head;
	min_node = current_node;
	while (current_node != NULL)
	{
		if (current_node->data < min_node->data)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

static int	get_node_position(t_list *stack, t_node *node)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = stack->head;
	while (current_node != NULL)
	{
		if (current_node == node)
			return (i);
		current_node = current_node->next;
		i++;
	}
	return (-1);
}

static void	rotate_min_to_top(t_list *stack)
{
	int		min_pos;
	t_node	*min_node;

	min_node = find_min_node(stack);
	if (min_node == NULL)
		return ;
	min_pos = get_node_position(stack, min_node);
	if (min_pos == -1)
		return ;
	while (stack->head->data != min_node->data)
	{
		if (min_pos <= stack->size / 2)
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_under_five_elements(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->size > 3)
	{
		rotate_min_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three_elements(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
