/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:48:58 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 15:50:35 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	reverse_rotate(t_list *stack)
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
