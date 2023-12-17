/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:52:23 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/15 22:52:25 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int reverse_rotate(t_list *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (stack->size <= 1)
		return (0);
	first = stack->head;
	last = stack->tail;
	second_last = stack->tail->prev;

	stack->head = last;
	stack->tail = second_last;

	last->next = first;
	first->prev = last;

	last->prev = NULL;
	second_last->next = NULL;
	return (1);
}

void	rra(t_list *stack)
{
	if (reverse_rotate(stack))
		ft_printf("rra\n");
}

void	rrb(t_list *stack)
{
	if (reverse_rotate(stack))
		ft_printf("rrb\n");
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		ft_printf("rrr\n");
}