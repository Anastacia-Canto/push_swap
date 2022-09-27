/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:04:02 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 17:17:55 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_lst **stack, int signal)
{
	t_lst	*temp;
	t_lst	*aux;
	int		nb1;
	int		nb2;

	if (size(stack) < 2)
		return ;
	aux = (*stack);
	temp = (*stack);
	nb1 = temp->number;
	temp = temp->next;
	nb2 = temp->number;
	aux->number = nb2;
	aux = aux->next;
	aux->number = nb1;
	aux = aux->next;
	if (signal == 1)
		return ;
	write(1, "sa\n", 3);
}

void	swap_b(t_lst **stack, int signal)
{
	t_lst	*temp;
	t_lst	*aux;
	int		nb1;
	int		nb2;

	if (size(stack) < 2)
		return ;
	aux = (*stack);
	temp = (*stack);
	nb1 = temp->number;
	temp = temp->next;
	nb2 = temp->number;
	aux->number = nb2;
	aux = aux->next;
	aux->number = nb1;
	if (signal == 1)
		return ;
	write(1, "sb\n", 3);
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	write(1, "ss\n", 3);
}

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_b && *stack_b)
	{
		add_front(stack_a, new_node((*stack_b)->number));
		del_one(stack_b);
		write(1, "pa\n", 3);
	}
	return ;
}

void	push_b(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_a && *stack_a)
	{
		add_front(stack_b, new_node((*stack_a)->number));
		del_one(stack_a);
		write(1, "pb\n", 3);
	}
	return ;
}
