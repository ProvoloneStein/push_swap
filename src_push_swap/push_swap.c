/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:31:12 by pstein            #+#    #+#             */
/*   Updated: 2019/12/23 15:53:15 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mass(int *s, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= ac - 1)
	{
		j = 0;
		s[i - 1] = ft_atoi(av[i]);
	}
}

int		main(int ac, char **av)
{
	t_num	*a_head;
	t_num	*b_head;
	int		list[ac - 1];
	t_param *params;

	if (!(b_head = makelist(0)))
		return (0);
	if ((params = param_list(1)) && ac > 1)
	{
		if (((a_head = makestack(ac, av, &params)) == NULL))
			return (ps_error1(&a_head, &b_head, &params));
	}
	else
		return (ps_error2(&b_head, &params));
	if (stack_check(a_head, b_head))
		return (ps_ok(&a_head, &b_head, &params));
	mass(list, params->max_n, av);
	ins_sort(list, &params, &a_head, &b_head);
	if (params->fd_option != 1)
		close(params->fd_option);
	return (ps_ok(&a_head, &b_head, &params));
}
