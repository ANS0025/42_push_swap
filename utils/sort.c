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
// void	simple_sort(t_list *stack_a, t_list *stack_b)
// {
// 	if (is_sorted(stack_a) || stack_a->size <= 1)
// 		return ;
// 	if (stack_a->size == 2)
// 		sa(stack_a);
// 	else if (stack_a->size == 3)
// 		//sort_three(stack_a);
// 	else if (stack_a->size == 4)
// 		//sort_four(stack_a, stack_b);
// 	else if (stack_a->size == 5)
// 		//sort_five(stack_a, stack_b);
// 	else
// 		//sort_hundred(stack_a, stack_b);
// }