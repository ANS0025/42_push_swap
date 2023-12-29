/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:09:37 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 00:12:20 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ソートアルゴリズムの場合分け
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
