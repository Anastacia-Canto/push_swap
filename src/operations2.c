/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:01:05 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/23 11:30:01 by anastacia        ###   ########.fr       */
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
		ft_printf("rra\n");
	}
	return ;
}

void	reverse_b(t_lst **stack, int signal)
{
	t_lst	*temp;
	t_lst	*aux;
	int		nb1;
	int		nb2;

	if (stack && *stack && size(stack) >= 2)
	{
		aux = (*stack);
		nb1 = aux->number;
		temp = (*stack);
		while (temp->next)
			temp = temp->next;
		nb2 = temp->number;
		aux->number = nb2;
		temp->number = nb1;
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
