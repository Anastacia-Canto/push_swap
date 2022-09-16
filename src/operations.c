/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:04:02 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/16 18:01:04 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*aux;
	int		nb1;
	int		nb2;

	if ((*stack)->size < 2)
		return ;
	aux = (*stack);
	temp = (*stack);
	nb1 = temp->number;
	temp = temp->next;
	nb2 = temp->number;
	aux->number = nb2;
	aux = aux->next;
	aux->number = nb1;
}
