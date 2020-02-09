/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:02:24 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 21:28:42 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid(char *line, t_num **a, t_num **b)
{
	if (ft_strequ(line, "sa"))
		return (1 + swap(a, 0, 0));
	else if (ft_strequ(line, "sb"))
		return (1 + swap(b, 0, 0));
	else if (ft_strequ(line, "ss"))
		return (1 + ss(a, b, 0, 0));
	else if (ft_strequ(line, "pa"))
		return (1 + push_from_to(b, a, 0, 0));
	else if (ft_strequ(line, "pb"))
		return (1 + push_from_to(a, b, 0, 0));
	else if (ft_strequ(line, "ra"))
		return (1 + rotate(a, 0, 0));
	else if (ft_strequ(line, "rb"))
		return (1 + rotate(b, 0, 0));
	else if (ft_strequ(line, "rr"))
		return (1 + rr(a, b, 0, 0));
	else if (ft_strequ(line, "rra"))
		return (1 + reverse_rotate(a, 0, 0));
	else if (ft_strequ(line, "rrb"))
		return (1 + reverse_rotate(b, 0, 0));
	else if (ft_strequ(line, "rrr"))
		return (1 + rrr(a, b, 0, 0));
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_num	*a;
	t_num	*b;
	char	*line;
	t_param	*p;

	if ((b = makelist(0)))
		if ((p = param_list(0)) && ac > 1)
		{
			if ((a = makestack(ac, av, &p)) == NULL)
				return (checker_error1(&a, &b, &p));
			while (get_next_line(p->fd_option, &line))
			{
				if (!(valid(line, &a, &b)))
					return (checker_error2(&a, &b, &p, &line));
				vizual_checker(a, b, p->v_option, line);
				free(line);
			}
			if (p->fd_option)
				close(p->fd_option);
			if (stack_check(a, b))
				return (viz1(&a, &b, p->v_option) && check_free(&a, &b, &p));
			return (checker_error3(&a, &b, &p));
		}
	return (checker_error4(&b, &p));
}
