/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:04:02 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 16:47:22 by anastacia        ###   ########.fr       */
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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	ft_printf("ss\n");
}

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_b && *stack_b)
	{
		add_front(stack_a, new_node((*stack_b)->number));
		del_one(stack_b);
		ft_printf("pa\n");
	}
	return ;
}

void	push_b(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_a && *stack_a)
	{
		add_front(stack_b, new_node((*stack_a)->number));
		del_one(stack_a);
		ft_printf("pb\n");
	}
	return ;
}
