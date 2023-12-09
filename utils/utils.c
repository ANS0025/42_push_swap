/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:10:31 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/09 15:10:32 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*-----	INITIALIZE FUNCTIONS -----*/
//create and initialize node
t_node *initialize_node(int data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->next = NULL;
	ft_printf("init node finished\n");
	return (node);
}

//initialize stack
void initialize_stack(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
}

//set the nodes for stack
void set_stack(t_list *stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_node 	*node;

	i = 0;
	if (argc < 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i++;
	}
	while (args[i])
	{
		node = initialize_node(ft_atoi(args[i]));
		insert_tail(stack, node);
		i++;
	}
	if (argc == 2)
		free_two_dimensional_array(args);
	ft_printf("stack set finished\n");
}

/*-----	PRINT FUNCTIONS -----*/
//print stack
void print_stack(t_list *stack)
{
	t_node *node;
	node = stack->head;
	while (node != NULL)
	{
		ft_printf("data:%d, index:%d, next: %p\n", node->data, node->index, node->next);
		node = node->next;
	}
}

/*-----	INSERT FUNCTIONS -----*/
//insert node at the end of the list
void insert_tail(t_list *list, t_node *node)
{
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
}

/*-----	CLEAN UP FUNCTIONS -----*/
//free two dimensional array
void free_two_dimensional_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

//free stack
void free_stack(t_list *stack)
{
	t_node *node;
	t_node *tmp;

	node = stack->head;
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack);
}