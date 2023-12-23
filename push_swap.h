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
void print_error(void);
void ft_free(char **array);
void free_stack(t_list *stack);
int	is_sorted(t_list *stack);
int has_duplicate(int argc, char **argv);
void validate_args(int argc, char **argv);
void sort_stack(t_list *stack_a, t_list *stack_b);

//operations
void	pa(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_a, t_list *stack_b);
void	rra(t_list *stack);
void	rrb(t_list *stack);
void	rrr(t_list *stack_a, t_list *stack_b);
void	ra(t_list *stack);
void	rb(t_list *stack);
void	rr(t_list *stack_a, t_list *stack_b);

//sorting algorithms
void	sort_three_elements(t_list *stack_a);
void	sort_under_five_elements(t_list *stack_a, t_list *stack_b);
void	radix_sort(t_list *stack_a, t_list *stack_b);


#endif