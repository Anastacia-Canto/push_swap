/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:04:02 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 10:48:44 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*aux;
	int		nb1;
	int		nb2;

	if ((*stack)->size < 2)
		return ;
	aux = (*stack);
	temp = (*stack);
	nb1 = temp->number;
	temp = temp->next;
	nb2 = temp->number;
	aux->number = nb2;
	aux = aux->next;
	aux->number = nb1;
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_b && *stack_b)
	{
		add_front(stack_a, new_node((*stack_b)->number));
		del_one(stack_b);
	}
	return ;
}

void	push_b(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_a && *stack_a)
	{
		add_front(stack_b, new_node((*stack_a)->number));
		del_one(stack_a);
	}
	return ;
}
