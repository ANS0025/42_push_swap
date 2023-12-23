/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:52:38 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/15 22:52:40 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_list *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size <= 1)
		return (0);
	first = stack->head;
	second = stack->head->next;

	first->next = second->next;
	first->prev = second;

	second->next = first;
	second->prev = NULL;
	stack->head = second;

	if (first->next)
		first->next->prev = first;
	else
		stack->tail = first;

	return (1);
}

void	sa(t_list *stack)
{
	if (swap(stack))
		ft_printf("sa\n");
}

void	sb(t_list *stack)
{
	if (swap(stack))
		ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (swap(stack_a) && swap(stack_b))
		ft_printf("ss\n");
}