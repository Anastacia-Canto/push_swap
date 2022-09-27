/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:03:09 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/27 17:18:49 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

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

/*Checking arguments*/
int		check_args(int argc, char **argv);
int		check_stranger_things(char *str);
int		check_duplicates(int argc, char **argv);
/*List creation and free*/
void	create_stack(t_lst **stack, char **argv, int argc);
t_lst	*new_node(int number);
void	add_back(t_lst **stack, t_lst *new);
// void	print_stack(t_lst **stack);
void	clear_stack(t_lst **stack);
void	add_front(t_lst **lst, t_lst *new);
void	del_one(t_lst **lst);
void	del_last(t_lst **lst);
int		size(t_lst **stack);
/*Operations on stakcs*/
void	swap_a(t_lst **stack, int signal);
void	swap_b(t_lst **stack, int signal);
void	ss(t_lst **stack_a, t_lst **stack_b);
void	push_a(t_lst **stack_a, t_lst **stack_b);
void	push_b(t_lst **stack_a, t_lst **stack_b);
void	rotate_a(t_lst **stack, int signal);
void	rotate_b(t_lst **stack, int signal);
void	rr(t_lst **stack_a, t_lst **stack_b);
void	reverse_a(t_lst **stack, int signal);
void	reverse_b(t_lst **stack, int signal);
void	rrr(t_lst **stack_a, t_lst **stack_b);
/*sorting*/
int		checker(t_lst **stack_a);
void	sort(t_lst **stack_a, t_lst **stack_b);
void	small_sort(t_lst **stack_a, t_lst **stack_b);
void	small_sort_a(t_lst **stack_a, t_lst **stack_b, int min, int max);
void	sort_three(t_lst **stack_a);
void	find_max(t_lst **stack, int *max);
void	find_min(t_lst **stack, int *min);
void	split(t_lst **stack_a, t_lst **stack_b, int first, int last);
void	big_sort(t_lst **stack_a, t_lst **stack_b, int chunks);
void	sort_b(t_lst **stack_a, t_lst **stack_b);

#endif