/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:40:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/26 17:29:48 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		min;
	int		max;
	int		first;
	int		pos;
	int		divisor;
	int		i;

	find_min(stack_a, &min);
	find_max(stack_a, &max);
	divisor = min + ((max - min) / 4);
	i = 0;
	while (i < 4)
	{
		first = min + (divisor * i);
		split(stack_a, stack_b, first, first + divisor);
		sort_b(stack_a, stack_b);
		i++;
	}
	temp = (*stack_a);
	pos = 0;
	while (temp->next && temp->number != min)
	{
		temp = temp->next;
		pos++;
	}
	// while ((*stack_a)->number != min)
	// {
	// 	if (pos < size(stack_a))
	// 		rotate_a(stack_a, 0);
	// 	else
	// 		reverse_a(stack_a, 0);
	// }
}
