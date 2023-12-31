/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:48:50 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 16:21:35 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_list *stack)
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
	first->prev = last;
	first->next = NULL;
	second->prev = NULL;
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

void	rr(t_list *stack_a, t_list *stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
		ft_printf("rr\n");
}
