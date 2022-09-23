/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:50:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/23 15:06:34 by anastacia        ###   ########.fr       */
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

void	small_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		max;
	int		min;

	temp = (*stack_a);
	find_min_max(stack_a, &min, &max);
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
	while (size(stack_b) > 0)
	{
		push_a(stack_a, stack_b);
		if ((*stack_a)->number == max)
			rotate_a(stack_a, 0);
	}
}

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

void	find_min_max(t_lst **stack_a, int *min, int *max)
{
	t_lst	*temp;

	temp = (*stack_a);
	*min = (*stack_a)->number;
	*max = (*stack_a)->number;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->number < *min)
			*min = temp->number;
		else if (temp->number > *max)
			*max = temp->number;
	}
}
