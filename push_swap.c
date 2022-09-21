/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:13:23 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 10:33:56 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (!check_args(argc, argv))
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	create_stack(&stack.a, argv, argc);
	print_stack(&stack.a);
	push_b(&stack.a, &stack.b);
	ft_printf("Pós push_b\n");
	ft_printf("stack.a:\n");
	print_stack(&stack.a);
	ft_printf("stack.b:\n");
	print_stack(&stack.b);
	ft_printf("---------------------\n");
	push_b(&stack.a, &stack.b);
	ft_printf("Pós push_b\n");
	ft_printf("stack.a:\n");
	print_stack(&stack.a);
	ft_printf("stack.b:\n");
	print_stack(&stack.b);
	ft_printf("---------------------\n");
	push_b(&stack.a, &stack.b);
	ft_printf("Pós push_b\n");
	ft_printf("stack.a:\n");
	print_stack(&stack.a);
	ft_printf("stack.b:\n");
	print_stack(&stack.b);
	clear_stack(&stack.a);
	clear_stack(&stack.b);
	return (0);
}
