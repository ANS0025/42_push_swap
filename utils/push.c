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

//TODO: check this function again
static int	push(t_list *stack_from, t_list *stack_to)
{
    t_node *first;
    t_node *second;

    if (stack_from->size == 0)
        return (0);

    first = stack_from->head;
    second = stack_from->head->next;

    stack_from->head = second;
    if (stack_from->head)  // Check if the new head is not NULL
        stack_from->head->prev = NULL;
    stack_from->size--;

    if (stack_from->size == 0)
        stack_from->tail = NULL;

    if (stack_to->head)  // Check if stack_to is not empty
        stack_to->head->prev = first;

    first->next = stack_to->head;
    first->prev = NULL;  // Set prev of first to NULL as it becomes new head
    stack_to->head = first;

    if (stack_to->size == 0)
        stack_to->tail = first;  // Set tail to first only if stack_to was empty

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