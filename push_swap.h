/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:43:18 by pstein            #+#    #+#             */
/*   Updated: 2019/12/26 14:21:27 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct		s_num
{
	int				data;
	struct s_num	*next;
}					t_num;

typedef struct		s_param
{
	int				max_n;
	int				v_option;
	int				fd_option;
	int				right;
	int				left;
}					t_param;

/*
** =================>checker.c<=================
** functions for find_place/push elements in stack
*/

int					valid(char *line, t_num **a, t_num **b);

/*
** =================>dop_alg.c<=================
** functions that works with stack in alg
*/

void				pre_sort(int *s, t_param *params, t_num **a, t_num **b);
void				mass_move(int *s, int n, t_num **b);
void				print_and_stuck(t_param **p, t_num **a, t_num **b);
void				sort_back1(int m, t_num **a, int fd);

/*
** =================>dop_sorting.c<=================
** functions for find_place/push elements in stack
*/

int					*place_in_mass(int *s, int n, int z, int j);
int					*place_in_mass_obr(int *s, int n, int i, int j);
int					s_in_mass_s1(int i, int *s1, int num);

/*
** =================>free_and_errors.c<=================
** free and errors
*/

int					check_free(t_num **a, t_num **b, t_param **p);
int					checker_error1(t_num **a, t_num **b, t_param **p);
int					checker_error2(t_num **a, t_num **b, t_param **p, char **l);
int					checker_error3(t_num **a, t_num **b, t_param **p);
int					checker_error4(t_num **b, t_param **p);

/*
** =================>make_list.c<=================
** making stack list
*/

int					isoption(int ac, char **av);
t_num				*make_stack2(int k, char **str);
t_num				*makestack(int ac, char **str, t_param **params);

/*
** =================>make_list2.c<=================
** making stack list
*/

t_param				*param_list(int num);
int					stack_check(t_num *a, t_num *b);
void				*free_lsts(t_num *list);
t_num				*makelist(int num);

/*
** =================>opt_from_right.c<=================
** gives rotate count from right
*/

int					opt_right(int **s, int n, int i);

/*
** =================>ps_errors.c<=================
** push_swap errors
*/

int					ps_error1(t_num **a, t_num **b, t_param **p);
int					ps_error2(t_num **b, t_param **p);
int					ps_ok(t_num **a, t_num **b, t_param **p);

/*
** =================>push_swap.c<=================
** push_swap
*/

void				mass(int *s, int ac, char **av);

/*
** =================>sort_three.c<=================
** three and five sort
*/

int					sort_three(t_num **a, t_param **p);
int					five_sort(t_num **a, t_num **b, t_param **p, int *s);

/*
** =================>sorting_dop.c<=================
** file with dop alg functions alg
*/

int					find_med(int *s, int n);
int					find_min(int *s, int n);

/*
** =================>sorting.c<=================
** file with my alg
*/

int					check_opt(int k, int n, int j2);
int					*supersort_spec(int *s, int n, int z, int j1);
int					opt_s1(int k, int n, int j, int max);
int					ins_sort(int *s, t_param **p, t_num **a, t_num **b);

/*
** =================>swap.c<=================
** push_swap functions
*/

int					push_from_to(t_num **a, t_num **b, int print, int fd);
int					rotate(t_num **a, int print, int fd);
int					reverse_rotate(t_num **a, int print, int fd);
int					rr(t_num **a, t_num **b, int print, int fd);
int					rrr(t_num **a, t_num **b, int print, int fd);

/*
** =================>swap2.c<=================
** push_swap functions
*/

int					swap(t_num **a, int print, int fd);
int					ss(t_num **a, t_num **b, int print, int fd);

/*
** =================>valid.c<=================
** file with dop alg functions alg
*/

int					valid_at(t_num *head, int num);
int					arg_isint(char *str);
int					valid_arg(char *s);

/*
** =================>viz.c<=================
** vizual debagger
*/

int					vizual_checker(t_num *a, t_num *b, int option, char *line);
int					viz1(t_num **a, t_num **b, int option);

#endif
