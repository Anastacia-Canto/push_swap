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
	printf_mem(stack_a);
	if (checker(stack_a, stack_b) == 1)
		return ;
	if (size(stack_a) <= 3)
	{
		while (checker(stack_a, stack_b) == 0)
			small_sort(stack_a);
	}
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

void	small_sort(t_lst **stack_a)
{
	t_lst	*temp;
	
	temp = (*stack_a)->next;
	if (temp->number < temp->prev->number)
		swap_a(stack_a, 0);
	else
		reverse_a(stack_a, 0);
	printf_mem(stack_a);
}

void	printf_mem(t_lst **stack)
{
	t_lst	*temp;

	temp = (*stack);
	while (temp->next)
	{
		ft_printf("#%d: %p\n", temp->number, temp->next);
		temp = temp->next;
	}
	ft_printf("#%d: %p\n", temp->number, temp->next);
}