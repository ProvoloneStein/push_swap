/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:09:11 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 15:36:59 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	makestuck2(t_num **head, t_num **nothead, int num, int i)
{
	if (i == 0)
	{
		*head = makelist(0);
		*nothead = *head;
	}
	else
	{
		(*nothead)->next = makelist(num);
		*nothead = (*nothead)->next;
	}
}

int			isoption(int ac, char **av)
{
	int j;

	j = 0;
	while (j < ac)
	{
		if (ft_strequ(av[j], "-viz") && j == ac - 1)
			return (1);
		j++;
	}
	return (0);
}

t_num		*make_stack2(int k, char **str)
{
	t_num	*head;
	t_num	*nothead;
	int		num;
	int		i;

	i = 0;
	while (i < k)
	{
		if (i)
		{
			if (!(arg_isint(str[i])))
				return (free_lsts(head));
			num = ft_atoi(str[i]);
			if (!(valid_at(head, num)))
				return (free_lsts(head));
		}
		makestuck2(&head, &nothead, num, i);
		i++;
	}
	return (head);
}

t_num		*makestack(int ac, char **str, t_param **params)
{
	int k;

	k = ac;
	if (!((*params)->v_option) && isoption(ac, str))
	{
		k = ac - 1;
		(*params)->v_option = 1;
	}
	if (ft_strequ(str[k - 2], "-open"))
	{
		if ((*params)->fd_option)
		{
			(*params)->fd_option = open(str[k - 1], O_CREAT | O_RDWR, 00777);
		}
		else
			(*params)->fd_option = open(str[k - 1], O_RDONLY);
		k = k - 2;
	}
	(*params)->max_n = k;
	return (make_stack2(k, str));
}
