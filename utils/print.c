/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihitonikoseki <akihitonikoseki@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:49:41 by akiseki           #+#    #+#             */
/*   Updated: 2024/01/03 15:51:18 by akihitoniko      ###   ########.fr       */
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

void	print_two_dimensional_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s ", array[i]);
		i++;
	}
	ft_printf("\n");
}
void ft_dd(void)
{
	ft_printf("dd\n");
	exit(1);
}
