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
t_node *initialize_node(int data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void initialize_stack(t_list *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

static t_node	*find_unindexed_min_node(t_list *stack)
{
	t_node	*current_node;
	t_node	*min_node;

	if (stack->head == NULL)
		return (NULL);
	current_node = stack->head;
	min_node = current_node;
	while (current_node != NULL)
	{
		if (current_node->index == 0 && current_node->data < min_node->data)
			min_node = current_node;
		current_node = current_node->next;
	}

	return (min_node);
}

t_node	*find_max_node(t_list *stack)
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

static void	set_index(t_list *stack)
{
	t_node	*current_node;
	t_node	*min_node;
	int		index;

	current_node = stack->head;
	index = 1;
	while(current_node != NULL)
	{
		min_node = find_unindexed_min_node(stack);
		if (min_node == NULL)
			break;
		min_node->index = index++;
		current_node = current_node->next;
	}
}

void set_stack(t_list *stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_node 	*node;

	i = 0;
	if (argc == 2)
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
	set_index(stack);
	if (argc == 2)
		ft_free(args);
}


/*-----	PRINT FUNCTIONS -----*/
void print_stack(t_list *stack)
{
	t_node *node;
	int i;

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

void print_error()
{
	ft_printf("Error\n");
	exit(1);
}

/*-----	INSERT FUNCTIONS -----*/
void insert_tail(t_list *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
		stack->size++;
	}
}

/*-----	CLEAN UP FUNCTIONS -----*/
// 二重配列のメモリ解放
void ft_free(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

// stackの全てのノードを解放
void free_stack(t_list *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->head;
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack);
}

/*-----	VALIDATOR FUNCTIONS -----*/
static int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int ft_strcmp(const char *s1, const char *s2) {
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *(unsigned char*)s1 - *(unsigned char*)s2;
}

int has_duplicate(int argc, char **argv) {
	int i = 1;
	while (i < argc) {
		int j = i + 1;
		while (j < argc) {
			if (ft_strcmp(argv[i], argv[j]) == 0) {
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}

void	validate_args(int argc, char **argv)
{
	int		i;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (has_duplicate(argc, args))
		print_error();
	while (args[i])
	{
		if (!isnum(args[i]))
			print_error();
		if (ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN)
			print_error();
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
