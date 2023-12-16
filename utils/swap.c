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

int	swap(t_list *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack->size <= 1)
		return (0);

	first = stack->head;
	second = stack->head->next;
	third = second->next;

	stack->head = second;
	second->next = first;
	first->next = third;
	if (stack->size == 2)
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