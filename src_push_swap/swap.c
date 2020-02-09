/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:43:33 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 16:25:39 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_from_to(t_num **a, t_num **b, int print, int fd)
{
	t_num	*lst1;
	t_num	*start1;
	t_num	*start2;
	t_num	*start3;

	if ((*a)->next)
	{
		start1 = (*a)->next;
		start2 = (*b)->next;
		start3 = start1->next;
		lst1 = start2;
		start2 = start1;
		start2->next = lst1;
		(*a)->next = start3;
		(*b)->next = start2;
		if (print == 1)
			write(fd, "pb\n", 3);
		else if (print == 2)
			write(fd, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	rotate(t_num **a, int print, int fd)
{
	t_num	*lst;
	t_num	*start;

	if ((*a)->next)
	{
		if ((*a)->next->next)
		{
			lst = (*a)->next;
			start = (*a)->next;
			(*a)->next = start->next;
			while (start && start->next)
				start = start->next;
			start->next = lst;
			start->next->next = NULL;
		}
		if (print == 1)
			write(fd, "ra\n", 3);
		else if (print == 2)
			write(fd, "rb\n", 3);
		return (1);
	}
	return (0);
}

int	rr(t_num **a, t_num **b, int print, int fd)
{
	if ((*a)->next && (*a)->next->next
			&& (*b)->next && (*b)->next->next)
	{
		rotate(a, 0, fd);
		rotate(b, 0, fd);
		if (print)
			write(fd, "rr\n", 3);
		return (1);
	}
	return (0);
}

/*
** print == 1 => a ; print == 2 => b
*/

int	reverse_rotate(t_num **a, int print, int fd)
{
	t_num	*lst;
	t_num	*start1;
	t_num	*start2;

	if ((*a)->next)
	{
		if ((*a)->next->next)
		{
			start1 = (*a)->next;
			start2 = (*a)->next;
			while (start1->next && start1->next->next)
				start1 = start1->next;
			lst = start1->next;
			start1->next = NULL;
			(*a)->next = lst;
			(*a)->next->next = start2;
		}
		if (print == 1)
			write(fd, "rra\n", 4);
		else if (print == 2)
			write(fd, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	rrr(t_num **a, t_num **b, int print, int fd)
{
	if ((*a)->next && (*b)->next)
	{
		reverse_rotate(a, 0, fd);
		reverse_rotate(b, 0, fd);
		if (print)
			write(fd, "rrr\n", 4);
		return (1);
	}
	return (0);
}
