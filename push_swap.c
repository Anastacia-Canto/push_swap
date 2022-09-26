/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:13:23 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/26 15:17:58 by anastacia        ###   ########.fr       */
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
	sort(&stack.a, &stack.b);
	// print_stack(&stack.a);
	clear_stack(&stack.a);
	clear_stack(&stack.b);
	return (0);
}
