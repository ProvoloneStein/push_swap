/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_dop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:24:32 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 16:19:56 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *s, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (s[i] < s[j])
			j = i;
		i++;
	}
	return (j);
}

int	find_med(int *s, int n)
{
	int	count1;
	int	j;
	int	i;

	count1 = 0;
	i = 0;
	while (count1 != (n / 2))
	{
		j = 0;
		while (j < n)
		{
			if (s[i] > s[j])
				count1++;
			j++;
		}
		if (count1 != (n / 2))
			count1 = 0;
		i++;
	}
	return (s[i - 1]);
}
