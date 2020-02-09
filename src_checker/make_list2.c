/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 19:46:46 by pstein            #+#    #+#             */
/*   Updated: 2020/02/09 21:01:25 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_param		*param_list(int num)
{
	t_param	*lst;

	if (!(lst = (t_param*)malloc(sizeof(t_param))))
		return (NULL);
	lst->max_n = num;
	lst->v_option = num;
	lst->fd_option = num;
	lst->right = num;
	lst->left = num;
	return (lst);
}

int			stack_check(t_num *a, t_num *b)
{
	t_num	*lst;

	lst = a;
	a = a->next;
	if (!(b->data) && !(b->next))
	{
		while (a->next)
		{
			if (a->data <= a->next->data)
			{
				a = a->next;
			}
			else
			{
				a = lst;
				return (0);
			}
		}
		a = lst;
		return (1);
	}
	return (0);
}

void		*free_lsts(t_num *list)
{
	t_num	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	return (NULL);
}

t_num		*makelist(int num)
{
	t_num	*lst;

	if (!(lst = (t_num*)malloc(sizeof(t_num))))
		return (NULL);
	lst->data = num;
	lst->next = NULL;
	return (lst);
}
