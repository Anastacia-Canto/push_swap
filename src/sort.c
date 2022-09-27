/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:50:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 16:13:27 by anastacia        ###   ########.fr       */
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
	else if (size(stack_a) <= 100)
		big_sort(stack_a, stack_b, 4);
	else
		big_sort(stack_a, stack_b, 8);
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
