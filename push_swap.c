/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:13:23 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/16 11:25:30 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]) || ft_atoi(argv[i]) > 2147483647
			|| ft_atoi(argv[i]) < -2147483648)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (0);
}
