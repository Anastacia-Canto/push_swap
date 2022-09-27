/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:40:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 14:26:23 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_lst **stack_a, t_lst **stack_b)
{
	int	min;
	int	max;
	int	range;
	int	i;

	find_min(stack_a, &min);
	find_max(stack_a, &max);
	range = (max - min) / 10;
	i = 10;
	while (i > 0)
	{
		i--;
		if (i == 9)
			split(stack_a, stack_b, min + i * range, max + 1);
		else
			split(stack_a, stack_b, min + i * range, min + (i + 1) * range);
		sort_b(stack_a, stack_b);
	}
}
