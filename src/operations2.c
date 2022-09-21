/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:01:05 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 16:53:04 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_lst **stack, int signal)
{
	t_lst	*temp;
	t_lst	*aux;

	if (stack && *stack && size(stack) >= 2)
	{
		aux = (*stack);
		temp = (*stack);
		while (temp->next)
			temp = temp->next;
		temp->prev->next = NULL;
		temp->next = aux;
		(*stack) = temp;
		if (signal == 1)
			return ;
		ft_printf("rra\n");
	}
	return ;
}

void	reverse_b(t_lst **stack, int signal)
{
	t_lst	*temp;
	t_lst	*aux;

	if (stack && *stack && size(stack) >= 2)
	{
		aux = (*stack);
		temp = (*stack);
		while (temp->next)
			temp = temp->next;
		temp->prev->next = NULL;
		temp->next = aux;
		(*stack) = temp;
		if (signal == 1)
			return ;
		ft_printf("rrb\n");
	}
	return ;
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_a(stack_a, 1);
	reverse_b(stack_b, 1);
	ft_printf("rrr\n");
}
