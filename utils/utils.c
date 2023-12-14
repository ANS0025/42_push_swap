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
	node->next = NULL;
	return (node);
}

void initialize_stack(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
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
		ft_printf("(%d) data:%d, index:%d, memory: %p, next: %p\n", 
			i, node->data, node->index, node, node->next);
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
/*-----	SORT CHECK -----*/
int is_sorted(t_list *stack)
{
	t_node *node;

	node = stack->head;
	while (node->next != NULL)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}