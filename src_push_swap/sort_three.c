/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 19:18:42 by pstein            #+#    #+#             */
/*   Updated: 2019/12/26 16:50:31 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three1(t_num **a, t_param **p)
{
	if ((*a)->next->data > (*a)->next->next->next->data)
	{
		if ((*a)->next->next->data > (*a)->next->next->next->data)
		{
			swap(a, 1, (*p)->fd_option);
			reverse_rotate(a, 1, (*p)->fd_option);
		}
		else
			rotate(a, 1, (*p)->fd_option);
	}
	else
		swap(a, 1, (*p)->fd_option);
}

int			sort_three(t_num **a, t_param **p)
{
	if ((*p)->max_n == 3)
	{
		if ((*a)->next->data > (*a)->next->next->data)
			swap(a, 1, (*p)->fd_option);
		return (1);
	}
	if ((*a)->next->data > (*a)->next->next->data)
		sort_three1(a, p);
	else
	{
		if ((*a)->next->data > (*a)->next->next->next->data)
			reverse_rotate(a, 1, (*p)->fd_option);
		else if ((*a)->next->next->data > (*a)->next->next->next->data)
		{
			swap(a, 1, (*p)->fd_option);
			rotate(a, 1, (*p)->fd_option);
		}
	}
	return (1);
}

int			five_sort(t_num **a, t_num **b, t_param **p, int *s)
{
	push_from_to(a, b, 1, (*p)->fd_option);
	s[4] = (*b)->next->data;
	push_from_to(a, b, 1, (*p)->fd_option);
	s[3] = (*b)->next->data;
	sort_three(a, p);
	s[0] = (*a)->next->data;
	s[1] = (*a)->next->next->data;
	s[2] = (*a)->next->next->next->data;
	return (1);
}
