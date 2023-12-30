/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:09:27 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/30 16:35:28 by akihitoniko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_list *stack)
{
	t_node	*node;
	int		i;

	node = stack->head;
	i = 1;
	if (node == NULL)
		ft_printf("stack is empty\n");
	while (node != NULL)
	{
		ft_printf("(%d) data:%d, index:%d, memory: %p, prev: %p, next: %p\n",
			i, node->data, node->index, node, node->prev, node->next);
		node = node->next;
		i++;
	}
}

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
