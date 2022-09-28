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

	zero = "0";
	i = 0;
	while (i < argc - 1)
	{
		i++;
		if ((*argv[i] - zero[0]) != 0)
		{
			if (!ft_atoi(argv[i]) || ft_atoi(argv[i]) > INT_MAX
				|| ft_atoi(argv[i]) < INT_MIN
				|| !check_stranger_things(argv[i]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		if (!check_duplicates(argc, argv))
			return (0);
	}
	if (argc <= 2)
		return (0);
	return (1);
}

int	check_duplicates(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc && i != j)
		{
			if (ft_strncmp(argv[i], argv[j], 11) == 0)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_stranger_things(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (i < (int)ft_strlen(str))
	{
		if ((str[i]) < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
