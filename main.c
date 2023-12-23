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

	//checker
	ft_printf("This is the stack before sorting:\n");
	print_stack(stack_a);
	ft_printf("%d\n\n", stack_a->size);
	//end checker

	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	//checker
	ft_printf("Sorting the stack:\n"); 
	//end checker

	sort_stack(stack_a, stack_b);

	//check
	ft_printf("\nThis is the stack after sorting:\n");
	print_stack(stack_a);
	ft_printf("\n\n");
	//end check

	free_stack(stack_a);
	free_stack(stack_b);

	//check
	print_stack(stack_a);
	print_stack(stack_b);
	//end check
	return (0);
}
