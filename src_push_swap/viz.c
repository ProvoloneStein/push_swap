/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:41:14 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 16:28:53 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	v_c(t_num *a, t_num *b)
{
	while (a->next || b->next)
	{
		if (a->next)
		{
			ft_printf("|  %d\t|", a->next->data);
			a = a->next;
		}
		else
			ft_printf("|\t|");
		ft_printf("\t");
		if (b->next)
		{
			ft_printf("|  %d\t|\n", b->next->data);
			b = b->next;
		}
		else
			ft_printf("|\t|\n");
	}
}

int			vizual_checker(t_num *a, t_num *b, int option, char *line)
{
	if (option)
	{
		ft_printf("\e[1;1H\e[2J");
		ft_printf("       {green}==>>%s<<=={eoc}\n", line);
		ft_printf("=========\t=========\n");
		v_c(a, b);
		ft_printf("=========\t=========\n");
		usleep(700000);
	}
	return (1);
}

static void	v_c1(t_num *a_k, t_num *b_k)
{
	while (a_k->next || b_k->next)
	{
		if (a_k->next)
		{
			ft_printf("|  %d\t|", a_k->next->data);
			a_k = a_k->next;
		}
		else
			ft_printf("|\t|");
		ft_printf("\t");
		if (b_k->next)
		{
			ft_printf("|  %d\t|\n", b_k->next->data);
			b_k = b_k->next;
		}
		else
			ft_printf("|\t|\n");
	}
}

int			viz1(t_num **a, t_num **b, int option)
{
	t_num	*a_k;
	t_num	*b_k;

	if (option)
	{
		a_k = *a;
		b_k = *b;
		ft_printf("\e[1;1H\e[2J");
		ft_printf("{green}");
		ft_printf("=========\t=========\n");
		v_c1(a_k, b_k);
		ft_printf("=========\t=========\n");
		sleep(1);
	}
	return (1);
}
