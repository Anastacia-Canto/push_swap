/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:52:14 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/16 16:58:05 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_args(int argc, char **argv)
{
	int		i;
	char	*zero;

	if (argc < 2)
		return (0);
	zero = "0";
	i = 0;
	while (i < argc - 1)
	{
		i++;
		if ((*argv[i] - zero[0]) != 0)
		{
			if (!ft_atoi(argv[i]) || ft_atoi(argv[i]) > INT_MAX
				|| ft_atoi(argv[i]) < INT_MIN || !check_duplicates(argc, argv))
			{
				ft_printf("Error\n");
				return (0);
			}
		}
	}
	return (1);
}

int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc && i != j)
		{
			if (ft_strncmp(argv[i], argv[j], 11) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}