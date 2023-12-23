/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:52:16 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/15 22:52:17 by akiseki          ###   ########.fr       */
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
	stack_from->head->prev = NULL;
	stack_from->size--;
	if (stack_from->size == 0)
		stack_from->tail = NULL;

	first->next = stack_to->head;
	stack_to->head->prev = first;
	stack_to->head = first;
	stack_to->size++;
	if (stack_to->size == 0)
		stack_to->tail = first;
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