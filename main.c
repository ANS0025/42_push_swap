/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:53:42 by akiseki           #+#    #+#             */
/*   Updated: 2023/12/09 14:53:49 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	validate_args(argc, argv);
	stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = (t_list *)malloc(sizeof(t_list));
	if (stack_a == NULL || stack_b == NULL)
		print_error();
	initialize_stack(stack_a);
	initialize_stack(stack_b);
	set_stack(stack_a, argc, argv);
	print_stack(stack_a);
	ft_printf("%d\n", stack_a->size);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);

	//check if freed.
	print_stack(stack_a);
	print_stack(stack_b);
	return (0);
}
