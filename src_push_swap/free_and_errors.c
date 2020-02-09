/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:51:28 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 16:53:31 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_free(t_num **a, t_num **b, t_param **p)
{
	free(*p);
	free_lsts(*b);
	free_lsts(*a);
	ft_printf("OK\n");
	return (1);
}

int	checker_error1(t_num **a, t_num **b, t_param **p)
{
	free(*p);
	free_lsts(*b);
	free_lsts(*a);
	ft_printf("Error\n");
	return (-1);
}

int	checker_error2(t_num **a, t_num **b, t_param **p, char **l)
{
	free(*p);
	free_lsts(*b);
	ft_printf("Error\n");
	free(*l);
	free_lsts(*a);
	return (-1);
}

int	checker_error3(t_num **a, t_num **b, t_param **p)
{
	free(*p);
	free_lsts(*b);
	ft_printf("KO\n");
	free_lsts(*a);
	return (-1);
}

int	checker_error4(t_num **b, t_param **p)
{
	free(*p);
	free_lsts(*b);
	return (0);
}
