/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:03:09 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/16 15:36:49 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	struct s_lst	*a;
	struct s_lst	*b;
}	t_stack;

typedef struct s_lst
{
	int				number;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

int		check_args(int argc, char **argv);
/*List creation and free*/
void	create_stack(t_lst **stack, char **argv, int argc);
t_lst	*new_node(int number);
void	add_back(t_lst **stack, t_lst *new);
void	clear_stack(t_lst **stack);

#endif