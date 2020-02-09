/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 00:02:43 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 16:26:09 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		valid_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i + 1] && (s[0] == '-' || s[0] == '+'))
			i++;
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int		arg_isint(char *str)
{
	long int	value;
	int			sign;

	if (!(valid_arg(str)))
		return (0);
	value = 0;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		value = value * 10 + (*str - '0');
		str++;
		if ((value * sign) > 2147483647 || (value * sign) < -2147483648)
			return (0);
	}
	return (1);
}

int		valid_at(t_num *head, int num)
{
	t_num	*kek;

	if (head && head->next)
	{
		kek = head->next;
		while (kek)
		{
			if (kek->data == num)
				return (0);
			kek = kek->next;
		}
		kek = head;
	}
	return (1);
}
