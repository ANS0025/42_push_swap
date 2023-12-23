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
