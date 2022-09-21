/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:50:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 17:32:46 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_lst **stack_a, t_lst **stack_b)
{
	if (checker(stack_a, stack_b) == 0)
		cycle_to_b(stack_a, stack_b);
	if (checker(stack_a, stack_b) == 0)
		cycle_to_a(stack_a, stack_b);
	if (checker(stack_a, stack_b) == 0)
		sort(stack_a, stack_b);
	else
		return ;
}

int	checker(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;

	if (size(stack_b) != 0 || size(stack_a) == 0)
		return (0);
	temp = (*stack_a);
	while (temp->next)
	{
		temp = temp->next;
		if (temp->number < temp->prev->number)
			return (0);
	}
	return (1);
}

void	cycle_to_b(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp_a;
	t_lst	*temp_b;

	while (size(stack_a) > 0)
	{
		if (size(stack_a) > 1)
		{
			temp_a = (*stack_a)->next;
			if (temp_a->number < temp_a->prev->number)
				swap_a(stack_a, 0);
		}
		push_b(stack_a, stack_b);
		if (size(stack_b) > 1)
		{
			temp_b = (*stack_b)->next;
			if (temp_b->number > temp_b->prev->number)
				swap_b(stack_b, 0);
		}
	}
}

void	cycle_to_a(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp_a;
	t_lst	*temp_b;

	while (size(stack_b) > 0)
	{
		if (size(stack_b) > 1)
		{
			temp_b = (*stack_b)->next;
			if (temp_b->number > temp_b->prev->number)
				swap_b(stack_b, 0);
		}
		push_a(stack_a, stack_b);
		if (size(stack_a) > 1)
		{
			temp_a = (*stack_a)->next;
			if (temp_a->number < temp_a->prev->number)
				swap_a(stack_a, 0);
		}
	}
}
