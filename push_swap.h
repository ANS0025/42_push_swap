/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:54:35 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/09 14:54:36 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//node
typedef struct __node
{
	int				data;
	int 			index;
	struct __node	*prev;
	struct __node	*next;
}	t_node;

//stack
typedef struct __list
{
	int 	size;
	t_node	*head;
	t_node	*tail;
}	t_list;

//util functions
t_node *initialize_node(int data);
void initialize_stack(t_list *stack);
void set_stack(t_list *stack, int argc, char **argv);
void print_stack(t_list *stack);
void insert_tail(t_list *stack, t_node *node);
void ft_free(char **array);
void free_stack(t_list *stack);
void validate_args(int argc, char **argv);
void print_error(void);

#endif