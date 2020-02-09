/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:40:54 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 21:41:14 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_opt(int k, int n, int j2)
{
	if (j2 > 0)
	{
		if ((n - k + 1) > (k - j2))
			return (k);
		return (k - 1 - n);
	}
	else
	{
		if ((n - k + 1 + j2) > (k))
			return (k);
		return (k - 1 - n);
	}
}

int			*supersort_spec(int *s, int n, int z, int j1)
{
	int	i;
	int	*k;

	k = s;
	i = 0;
	while (i < z)
	{
		if (k[0] != j1)
		{
			while (i < z)
			{
				k[n + 1] = k[i];
				k[i] = k[i + 1];
				k[i + 1] = k[n + 1];
				i++;
			}
			i = 0;
		}
		else
			i++;
	}
	return (k);
}

static int	sstruck(int **s, int n, int i, int j2)
{
	int	j;
	int	j1;

	j = i;
	if (i == 1)
	{
		*s = place_in_mass(*s, n, i, 0);
		return (0);
	}
	else if (i)
	{
		j1 = (*s)[i];
		j = s_in_mass_s1(i, *s, j1);
		*s = place_in_mass(*s, n, i, j);
		j = check_opt(j, i - 1, j2);
		*s = supersort_spec(*s, n, i, j1);
	}
	return (j);
}

int			opt_s1(int k, int n, int j, int max)
{
	int	num;

	num = 0;
	if (n == max - 1)
		return (0);
	if (j > 0)
	{
		if (k > j)
			num = k;
		else
			num = j;
		if ((n - k + j) > num)
			return (num);
		return (n - k + j);
	}
	if ((k - n) < j)
		num = k - n;
	else
		num = j;
	if (num < (-k + j))
		return (k - j);
	return (-num);
}

int			ins_sort(int *s, t_param **p, t_num **a, t_num **b)
{
	int	i;
	int	*lel;

	lel = s;
	if ((*p)->max_n == 6 && five_sort(a, b, p, lel))
		i = 3;
	else if ((*p)->max_n == 4 || (*p)->max_n == 3)
		return (sort_three(a, p));
	else
	{
		pre_sort(s, *p, a, b);
		mass_move(lel, (*p)->max_n - 1, b);
		i = 0;
	}
	while (i < (*p)->max_n - 1)
	{
		(*p)->right = opt_right(&s, (*p)->max_n - 1, i);
		(*p)->left = sstruck(&lel, (*p)->max_n - 1, i, 0);
		print_and_stuck(p, a, b);
		push_from_to(b, a, 2, (*p)->fd_option);
		i++;
	}
	(*p)->left = check_opt(find_min(lel, (*p)->max_n - 1), (*p)->max_n - 2, 0);
	sort_back1((*p)->left, a, (*p)->fd_option);
	return (1);
}
