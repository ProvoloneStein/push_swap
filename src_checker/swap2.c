/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:35:44 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 16:25:49 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_num **a, int print, int fd)
{
	t_num	*tmp;
	t_num	*start;

	if ((*a)->next)
	{
		start = (*a)->next;
		if (start->next)
		{
			tmp = start;
			start = start->next;
			tmp->next = start->next;
			start->next = tmp;
			(*a)->next = start;
			if (print == 1)
				write(fd, "sa\n", 3);
			else if (print == 2)
				write(fd, "sb\n", 3);
			return (1);
		}
	}
	return (0);
}

int	ss(t_num **a, t_num **b, int print, int fd)
{
	if ((*a)->next && (*b)->next)
	{
		swap(a, 0, fd);
		swap(b, 0, fd);
		if (print)
			write(1, "ss\n", 3);
		return (1);
	}
	else
		return (0);
}
