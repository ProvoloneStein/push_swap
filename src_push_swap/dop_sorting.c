/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:55:07 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 15:26:54 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*place_in_mass(int *s, int n, int z, int j)
{
	int	i;

	i = z;
	while (j < i)
	{
		s[n + 1] = s[i - 1];
		s[i - 1] = s[i];
		s[i] = s[n + 1];
		i--;
	}
	return (s);
}

int			*place_in_mass_obr(int *s, int n, int i, int j)
{
	int	k;
	int	m;

	k = i;
	m = j;
	while (m)
	{
		while (k + 1 < n)
		{
			s[n + 1] = s[k];
			s[k] = s[k + 1];
			s[k + 1] = s[n + 1];
			k++;
		}
		k = i;
		m--;
	}
	return (s);
}

static int	s_in_mass_s2(int i, int *s1, int num)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (k < i)
	{
		if (s1[k] < num && s1[k] > s1[j])
			j = k;
		k++;
	}
	if (j == (i - 1))
		return (0);
	else
		return (j + 1);
}

int			s_in_mass_s1(int i, int *s1, int num)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (j < i && s1[j] < num)
		j++;
	while (k < i)
	{
		if (s1[k] > num && s1[k] < s1[j])
			j = k;
		k++;
	}
	if (j == i)
		return (s_in_mass_s2(i, s1, num));
	return (j);
}
