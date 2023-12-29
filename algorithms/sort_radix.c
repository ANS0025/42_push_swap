/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:31:40 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/15 22:31:42 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(t_list *stack)
{
	int	max_bits;

	max_bits = 0;
	while ((stack->size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;

	max_bits = get_max_bits(stack_a);
	size = stack_a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((stack_a->head->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
