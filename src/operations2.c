/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:01:05 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 13:52:35 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}

void	rotate(t_lst **stack)
{
	if (stack && *stack && size(stack) >= 2)
	{
		add_back(stack, new_node((*stack)->number));
		del_one(stack);
	}
	return ;
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
