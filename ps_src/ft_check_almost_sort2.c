/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_almost_sort2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:03:01 by manki             #+#    #+#             */
/*   Updated: 2019/09/01 19:15:30 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_sort3_a(t_list **a, t_list **output, t_byte bol)
{
	if (bol == 1)
		ft_sort3_complicated_a(a[0], NULL, output);
	else
	{
		while (ft_lstlen(a[0]) == 3 && !ft_list_is_sort(a[0]))
		{
			if (ft_nbdiff(ft_lstmax(a[0]), a[0]->content) == 0 &&
					ft_list_is_sort(a[0]->next))
				ft_add_instr("ra", a, NULL, output);
			else if (ft_nbdiff(a[0]->content, a[0]->next->content) < 0)
				ft_add_instr("rra", a, NULL, output);
			else if ((ft_nbdiff(a[0]->content, a[0]->next->content) > 0 &&
						(ft_nbdiff(ft_lstmin(a[0]), a[0]->next->content) == 0))
					|| ft_list_is_reverse_sort(a[0]))
				ft_add_instr("sa", a, NULL, output);
		}
		if (ft_lstlen(a[0]) == 2 && !ft_list_is_sort(a[0]))
			ft_add_instr("sa", a, NULL, output);
	}
}

void		ft_sort_four(t_list **a, t_list **b, t_list **output, t_byte bol)
{
	int		stop;
	char	*min;

	stop = 0;
	min = ft_lstmin(a[0]);
	while (!stop)
	{
		if (!(ft_nbdiff(a[0]->content, min)))
		{
			ft_add_instr("pb", a, b, output);
			stop = 1;
		}
		else
			ft_add_instr("ra", a, b, output);
	}
	ft_sort3_a(a, output, bol);
	ft_add_instr("pa", a, b, output);
}

void		ft_sort_five(t_list **a, t_list **b, t_list **output, t_byte bol)
{
	int		parse;
	char	*min;
	char	*mx;

	parse = 0;
	min = ft_lstmin(a[0]);
	mx = ft_lstmax(a[0]);
	while (parse < 2)
	{
		if (!(ft_nbdiff(a[0]->content, min)) || !(ft_nbdiff(a[0]->content, mx)))
		{
			ft_add_instr("pb", a, b, output);
			parse++;
		}
		else
			ft_add_instr("ra", a, b, output);
	}
	ft_sort3_a(a, output, bol);
	ft_add_instr("pa", a, b, output);
	if (ft_nbdiff(a[0]->content, a[0]->next->content) > 0)
		ft_add_instr("ra", a, b, output);
	ft_add_instr("pa", a, b, output);
	if (ft_nbdiff(a[0]->content, a[0]->next->content) > 0)
		ft_add_instr("ra", a, b, output);
}

void		ft_sort_six(t_list **a, t_list **b, t_list **output)
{
	int		stop;
	char	*min;

	stop = 0;
	min = ft_lstmin(a[0]);
	while (!stop)
	{
		if (!(ft_nbdiff(a[0]->content, min)))
		{
			ft_add_instr("pb", a, b, output);
			stop = 1;
		}
		else
			ft_add_instr("ra", a, b, output);
	}
	ft_sort_five(a, b, output, 0);
	ft_add_instr("pa", a, b, output);
}

void		ft_sort_seven(t_list **a, t_list **b, t_list **output)
{
	int		stop;
	char	*min;

	stop = 0;
	min = ft_lstmin(a[0]);
	while (!stop)
	{
		if (!(ft_nbdiff(a[0]->content, min)))
		{
			ft_add_instr("pb", a, b, output);
			stop = 1;
		}
		else
			ft_add_instr("ra", a, b, output);
	}
	ft_sort_six(a, b, output);
	ft_add_instr("pa", a, b, output);
}
