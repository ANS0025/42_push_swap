#include "push_swap.h"

static t_node	*find_max_node(t_list *stack)
{
	t_node	*current_node;
	t_node	*max_node;

	if (stack->head == NULL)
		return (NULL);
	current_node = stack->head;
	max_node = current_node;
	while (current_node != NULL)
	{
		if (current_node->data > max_node->data)
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}

void	sort_three_elements(t_list *stack_a)
{
	t_node	*head;
	t_node	*tail;
	t_node	*highest;

	head = stack_a->head;
	tail = stack_a->tail;
	highest = find_max_node(stack_a);
	while (!is_sorted(stack_a))
	{
		if (head->index == highest->index)
			ra(stack_a);
		else if (head->next->index == highest->index)
			rra(stack_a);
		else if (tail->index == highest->index)
			sa(stack_a);
	}
}