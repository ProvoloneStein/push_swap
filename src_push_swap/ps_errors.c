/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:04 by pstein            #+#    #+#             */
/*   Updated: 2019/12/26 17:01:33 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_error1(t_num **a, t_num **b, t_param **p)
{
	free(*p);
	free_lsts(*a);
	free_lsts(*b);
	ft_printf("Error\n");
	return (-1);
}

int	ps_error2(t_num **b, t_param **p)
{
	free(*p);
	free_lsts(*b);
	return (0);
}

int	ps_ok(t_num **a, t_num **b, t_param **p)
{
	free(*p);
	free_lsts(*a);
	free_lsts(*b);
	return (0);
}
