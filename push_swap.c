/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:13:23 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/16 15:37:18 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]) || ft_atoi(argv[i]) > INT_MAX
			|| ft_atoi(argv[i]) < INT_MIN)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (!check_args(argc, argv))
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	create_stack(&stack.a, argv, argc);
	clear_stack(&stack.a);
	return (0);
}
