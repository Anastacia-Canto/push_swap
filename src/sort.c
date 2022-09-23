/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:50:35 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/23 15:42:28 by anastacia        ###   ########.fr       */
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
