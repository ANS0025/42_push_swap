/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:32:55 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 15:35:58 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) || stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three_elements(stack_a);
	else if (stack_a->size <= 5)
		sort_under_five_elements(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
