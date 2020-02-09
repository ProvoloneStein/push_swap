/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:50:16 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 14:46:24 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pre_sort(int *s, t_param *params, t_num **a, t_num **b)
{
	int	med;
	int	i;

	i = 0;
	med = find_med(s, params->max_n - 1);
	while (i < params->max_n - 1)
	{
		if (s[i] < med || i == 0)
			push_from_to(a, b, 1, params->fd_option);
		else
		{
			push_from_to(a, b, 1, params->fd_option);
			rotate(b, 2, params->fd_option);
		}
		i++;
	}
}

void		mass_move(int *s, int n, t_num **b)
{
	int		i;
	t_num	*kek;

	i = 0;
	kek = (*b);
	while (++i <= n)
	{
		s[i - 1] = kek->next->data;
		kek = kek->next;
	}
}

static void	print_and_stuck2(t_param **p, t_num **a, t_num **b)
{
	while ((*p)->left > 0)
	{
		rotate(a, 1, (*p)->fd_option);
		(*p)->left--;
	}
	while ((*p)->right > 0)
	{
		rotate(b, 2, (*p)->fd_option);
		(*p)->right--;
	}
	while ((*p)->left < 0)
	{
		reverse_rotate(a, 1, (*p)->fd_option);
		(*p)->left++;
	}
	while ((*p)->right < 0)
	{
		reverse_rotate(b, 2, (*p)->fd_option);
		(*p)->right++;
	}
}

void		print_and_stuck(t_param **p, t_num **a, t_num **b)
{
	while ((*p)->right || (*p)->left)
	{
		if ((*p)->right > 0 && (*p)->left > 0 && rr(a, b, 1, (*p)->fd_option))
		{
			(*p)->right--;
			(*p)->left--;
		}
		else if ((*p)->right < 0
				&& (*p)->left < 0 && rrr(a, b, 1, (*p)->fd_option))
		{
			(*p)->right++;
			(*p)->left++;
		}
		else
			print_and_stuck2(p, a, b);
	}
}

void		sort_back1(int m, t_num **a, int fd)
{
	if (m > 0)
	{
		while (m > 0)
		{
			rotate(a, 1, fd);
			m--;
		}
	}
	else
	{
		while (m < 0)
		{
			reverse_rotate(a, 1, fd);
			m++;
		}
	}
}
