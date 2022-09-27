/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:41:03 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 17:32:12 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_lst **stack_a, t_lst **stack_b, int chunks)
{
	int	min;
	int	max;
	int	range;
	int	i;
	int	last_chunk;

	find_min(stack_a, &min);
	find_max(stack_a, &max);
	range = (max - min) / chunks;
	last_chunk = chunks - 1;
	i = chunks;
	while (i > 0)
	{
		i--;
		if (i == last_chunk)
			split(stack_a, stack_b, min + i * range, max + 1);
		else
			split(stack_a, stack_b, min + i * range, min + (i + 1) * range);
		sort_b(stack_a, stack_b);
	}
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

void	split(t_lst **stack_a, t_lst **stack_b, int first, int last)
{
	int		count;
	t_lst	*temp;

	temp = (*stack_a);
	count = 0;
	while (temp->next)
	{
		if (temp->number >= first && temp->number < last)
			count++;
		temp = temp->next;
	}
	if (temp->number >= first && temp->number < last)
		count++;
	while (count > 0)
	{
		if ((*stack_a)->number >= first && (*stack_a)->number < last)
		{
			push_b(stack_a, stack_b);
			count--;
		}
		else
			rotate_a(stack_a, 0);
	}
	return ;
}

void	sort_b(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		max;
	int		pos;

	while (size(stack_b) > 0)
	{
		find_max(stack_b, &max);
		temp = (*stack_b);
		pos = 0;
		while (temp->number != max)
		{
			temp = temp->next;
			pos++;
		}
		while ((*stack_b)->number != max)
		{
			if (pos < size(stack_b) / 2)
				rotate_b(stack_b, 0);
			else
				reverse_b(stack_b, 0);
		}
		push_a(stack_a, stack_b);
	}
	return ;
}
