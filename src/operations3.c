/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:52:11 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 16:52:36 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_lst **stack, int signal)
{
	if (stack && *stack && size(stack) >= 2)
	{
		add_back(stack, new_node((*stack)->number));
		del_one(stack);
		if (signal == 1)
			return ;
		ft_printf("ra\n");
	}
	return ;
}

void	rotate_b(t_lst **stack, int signal)
{
	if (stack && *stack && size(stack) >= 2)
	{
		add_back(stack, new_node((*stack)->number));
		del_one(stack);
		if (signal == 1)
			return ;
		ft_printf("rb\n");
	}
	return ;
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	ft_printf("rr\n");
}
