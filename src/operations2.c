/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:01:05 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 17:18:10 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_lst **stack, int signal)
{
	t_lst	*temp;

	if (stack && *stack && size(stack) >= 2)
	{
		temp = (*stack);
		while (temp->next)
			temp = temp->next;
		add_front(stack, new_node(temp->number));
		del_last(stack);
		if (signal == 1)
			return ;
		write(1, "rra\n", 4);
	}
	return ;
}

void	reverse_b(t_lst **stack, int signal)
{
	t_lst	*temp;

	if (stack && *stack && size(stack) >= 2)
	{
		temp = (*stack);
		while (temp->next)
			temp = temp->next;
		add_front(stack, new_node(temp->number));
		del_last(stack);
		if (signal == 1)
			return ;
		write(1, "rrb\n", 4);
	}
	return ;
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_a(stack_a, 1);
	reverse_b(stack_b, 1);
	write(1, "rrr\n", 4);
}
