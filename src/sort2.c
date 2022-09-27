/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:41:03 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 17:10:14 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_lst **stack_a)
{
	t_lst	*temp;

	while (checker(stack_a) == 0)
	{
		temp = (*stack_a)->next;
		if (temp->number < temp->prev->number)
			swap_a(stack_a, 0);
		else
			reverse_a(stack_a, 0);
	}
	return ;
}

void	small_sort(t_lst **stack_a, t_lst **stack_b)
{
	int		max;
	int		min;

	find_min(stack_a, &min);
	find_max(stack_a, &max);
	small_sort_a(stack_a, stack_b, min, max);
	while (size(stack_b) > 0)
	{
		push_a(stack_a, stack_b);
		if ((*stack_a)->number == max)
			rotate_a(stack_a, 0);
	}
}

void	small_sort_a(t_lst **stack_a, t_lst **stack_b, int min, int max)
{
	t_lst	*temp;

	while (checker(stack_a) == 0)
	{
		temp = (*stack_a);
		while (temp->next)
			temp = temp->next;
		if ((*stack_a)->number == min || (*stack_a)->number == max)
			push_b(stack_a, stack_b);
		else if ((*stack_a)->number > temp->number)
			rotate_a(stack_a, 0);
		else
		{
			temp = (*stack_a)->next;
			if ((*stack_a)->number < temp->number)
				rotate_a(stack_a, 0);
			else
				swap_a(stack_a, 0);
		}
	}
	return ;
}

void	find_max(t_lst **stack, int *max)
{
	t_lst	*temp;

	temp = (*stack);
	*max = (*stack)->number;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->number >= *max)
			*max = temp->number;
	}
	return ;
}

void	find_min(t_lst **stack, int *min)
{
	t_lst	*temp;

	temp = (*stack);
	*min = (*stack)->number;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->number <= *min)
			*min = temp->number;
	}
	return ;
}
