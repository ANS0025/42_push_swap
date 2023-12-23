/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:31:40 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/15 22:31:42 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*-----	SORT CHECK -----*/
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
/*-----	SORTING ALGORITHMS -----*/
void	sort_three_elements(t_list *stack_a)
{
	t_node	*head;
	t_node	*tail;
	t_node	*highest;

	head = stack_a->head;
	tail = stack_a->tail;
	highest = find_max_node(stack_a);
	while (!is_sorted(stack_a))
	{
		if (head->index == highest->index)
			ra(stack_a);
		else if (head->next->index == highest->index)
			rra(stack_a);
		else if (tail->index == highest->index)
			sa(stack_a);
	}
}

//TODO: Check if implementation is correct
void	sort_under_five_elements(t_list *stack_a, t_list *stack_b)
{
	int		i;
	int		min_index;
	t_node	*min_node;

	i = 0;
	while (i < 2)
	{
		min_node = find_unindexed_min_node(stack_a);
		min_index = min_node->index;
		if (min_index <= stack_a->size / 2)
			while (stack_a->head->index != min_index)
				ra(stack_a);
		else
			while (stack_a->head->index != min_index)
				rra(stack_a);
		pb(stack_a, stack_b);
		i++;
	}
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
//TODO: Check if implementation is correct
void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int		i;
	int		j;
	int		bit;
	int		bit_count;
	t_node	*node;

	i = 0;
	bit_count = 0;
	while (i < stack_a->size)
	{
		j = 0;
		while (j < stack_a->size)
		{
			node = stack_a->head;
			bit = (node->data >> bit_count) & 1;
			if (bit == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		bit_count++;
		i++;
	}
}

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) || stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size <= 3)
		sort_three_elements(stack_a);
	else if (stack_a->size <= 5)
		sort_under_five_elements(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

