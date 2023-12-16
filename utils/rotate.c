/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:52:32 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/15 22:52:33 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_list *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack->size <= 1)
		return (0);
	first = stack->head;
	second = stack->head->next;
	last = stack->tail;
	stack->head = second;
	stack->tail = first;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_list *stack)
{
	if (rotate(stack))
		ft_printf("ra\n");
}

void	rb(t_list *stack)
{
	if (rotate(stack))
		ft_printf("rb\n");
}