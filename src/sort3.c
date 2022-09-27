/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:40:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 13:31:43 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		min;
	int		max;
	int		divisor;
	int		count;
	int		i;

	find_min(stack_a, &min);
	find_max(stack_a, &max);
	divisor = ((max - min) / 4);
	i = 0;
	while (i < 4)
	{
		count = 0;
		temp = (*stack_a);
		while (temp->next)
		{
			if (temp->number >= (min + divisor * i)
				&& temp->number < (min + divisor + divisor * i))
				count++;
			temp = temp->next;
		}
		if (temp->number >= (min + divisor * i)
				&& temp->number < (min + divisor + divisor * i))
				count++;
		while (count > 0)
		{
			split(stack_a, stack_b, min + divisor * i, min + divisor + divisor * i);
			count--;
		}
		sort_b(stack_a, stack_b);
		i++;
	}
}
