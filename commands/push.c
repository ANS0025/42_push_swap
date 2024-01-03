/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:33:39 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 15:36:55 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_list *stack_from, t_list *stack_to)
{
	t_node	*first;
	t_node	*second;

	if (stack_from->size == 0)
		return (0);
	first = stack_from->head;
	second = stack_from->head->next;
	stack_from->head = second;
	if (stack_from->head)
		stack_from->head->prev = NULL;
	stack_from->size--;
	if (stack_from->size == 0)
		stack_from->tail = NULL;
	if (stack_to->head)
		stack_to->head->prev = first;
	first->next = stack_to->head;
	first->prev = NULL;
	stack_to->head = first;
	if (stack_to->size == 0)
		stack_to->tail = first;
	stack_to->size++;
	return (1);
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	if (push(stack_b, stack_a))
		ft_printf("pa\n");
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	if (push(stack_a, stack_b))
		ft_printf("pb\n");
}
