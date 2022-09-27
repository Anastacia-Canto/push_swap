/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:44:45 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 17:05:16 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
		return ;
	}
}

void	del_one(t_lst **lst)
{
	t_lst	*temp;

	if (!lst || !*lst)
		return ;
	temp = (*lst);
	temp = temp->next;
	free (*lst);
	(*lst) = temp;
}

void	del_last(t_lst **lst)
{
	t_lst	*temp;

	if (!lst || !*lst)
		return ;
	temp = (*lst);
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	free (temp);
}

int	size(t_lst **stack)
{
	t_lst	*temp;
	int		size;

	if (!stack || !*stack)
		return (0);
	size = 0;
	temp = (*stack);
	while (temp->next)
	{
		size++;
		temp = temp->next;
	}
	size++;
	return (size);
}
