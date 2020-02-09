/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_from_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:32:04 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 15:44:00 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** find place in mass and return rotate count
*/

static void	pim_obr(int **s, int n, int i, int m1)
{
	if (m1 >= 0)
		*s = place_in_mass_obr(*s, n, i, m1);
	else
		*s = place_in_mass_obr(*s, n, i, n + m1 - i);
}

static void	dop_dop_orj3(int *m, int j3, int k, int *m1)
{
	if (*m > (j3 + k))
	{
		*m = j3;
		*m1 = k;
	}
}

static void	dop_dop_orj4(int *m, int j4, int k, int *m1)
{
	if (*m > (j4 + k))
	{
		*m = j4;
		*m1 = -1 - k;
	}
}

static int	dop_opt_right(int **s, int n, int i, int k)
{
	int	j3;
	int	j4;
	int	m;
	int m1;

	m = n;
	while (k < n - i)
	{
		j3 = m;
		j4 = m;
		if ((i + k) < n)
			j3 = opt_s1(s_in_mass_s1(i, *s, (*s)[i + k]), i, k, n);
		if ((n - 1 - k) >= i)
			j4 = opt_s1(s_in_mass_s1(i, *s, (*s)[n - 1 - k]), i, -k - 1, n);
		dop_dop_orj3(&m, j3, k, &m1);
		dop_dop_orj4(&m, j4, k, &m1);
		k++;
	}
	return (m1);
}

int			opt_right(int **s, int n, int i)
{
	int	k;
	int	m1;

	k = 0;
	m1 = dop_opt_right(s, n, i, k);
	pim_obr(s, n, i, m1);
	return (m1);
}
