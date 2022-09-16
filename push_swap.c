/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:13:23 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/16 15:52:46 by anastacia        ###   ########.fr       */
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
	clear_stack(&stack.a);
	return (0);
}
