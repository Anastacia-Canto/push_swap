/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:22:53 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/21 11:58:52 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack(t_lst **stack, char **argv, int argc)
{
	int	i;

	*stack = new_node((int)ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		add_back(stack, new_node((int)ft_atoi(argv[i])));
		i++;
	}
}

t_lst	*new_node(int number)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	add_back(t_lst **stack, t_lst *new)
{
	t_lst	*temp;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void	clear_stack(t_lst **stack)
{
	t_lst	*temp;

	if (!stack || !*stack)
		return ;
	while (stack && *stack)
	{
		temp = (*stack)->next;
		free (*stack);
		*stack = temp;
	}
}

void	print_stack(t_lst **stack)
{
	t_lst	*temp;

	if (!stack || !*stack)
		return ;
	temp = (*stack);
	while (temp->next)
	{
		ft_printf("%d\n", temp->number);
		temp = temp->next;
	}
	ft_printf("%d\n", temp->number);
}
