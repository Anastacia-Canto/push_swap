/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:50:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/26 15:18:27 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_lst **stack_a, t_lst **stack_b)
{
	if (size(stack_a) == 0 || (checker(stack_a) == 1 && size(stack_b) == 0))
		return ;
	if (size(stack_a) <= 3)
		sort_three(stack_a);
	else if (size(stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
	return ;
}

int	checker(t_lst **stack_a)
{
	t_lst	*temp;

	temp = (*stack_a);
	while (temp->next)
	{
		temp = temp->next;
		if (temp->number < temp->prev->number)
			return (0);
	}
	return (1);
}

void	big_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		min;
	int		max;
	int		pivot;
	int		pos;

	find_min_max(stack_a, &min, &max);
	pivot = min + ((max - min) / 2);
	split(stack_a, stack_b, pivot, 0);
	sort_b(stack_a, stack_b);
	split(stack_a, stack_b, pivot, 1);
	sort_b(stack_a, stack_b);
	temp = (*stack_a);
	pos = 0;
	while (temp->next && temp->number != min)
	{
		temp = temp->next;
		pos++;
	}
	while ((*stack_a)->number != min)
	{
		if (pos < size(stack_a))
			rotate_a(stack_a, 0);
		else
			reverse_a(stack_a, 0);
	}
}

void	sort_b(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		min;
	int		max;
	int		pos;

	while (size(stack_b) > 0)
	{
		find_min_max(stack_b, &min, &max);
		temp = (*stack_b);
		pos = 0;
		while (temp->number != max)
		{
			temp = temp->next;
			pos++;
		}
		if (pos < size(stack_b) / 2)
		{
			while ((*stack_b)->number != max)
				rotate_b(stack_b, 0);
		}
		else
		{
			while ((*stack_b)->number != max)
				reverse_b(stack_b, 0);
		}
		push_a(stack_a, stack_b);
	}
	return ;
}

void	split(t_lst **stack_a, t_lst **stack_b, int pivot, int signal)
{
	t_lst	*temp;
	int		i;
	int		control;

	i = 0;
	control = size(stack_a);
	while (i < control)
	{
		temp = (*stack_a);
		if (temp->number < pivot && signal == 0)
			push_b(stack_a, stack_b);
		else if (temp->number >= pivot && signal == 1)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a, 0);
		i++;
	}
	return ;
}
