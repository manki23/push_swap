/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_almost_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:42:56 by manki             #+#    #+#             */
/*   Updated: 2019/09/02 11:52:14 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			ft_add_instr(char *in, t_list **a, t_list **b, t_list **out)
{
	ft_apply_instruction(in, a, b);
	ft_lsadd(out, in, ft_strlen(in) + 1);
}

static t_byte	ft_end_swap(t_list *lst)
{
	t_list		*tmp;
	t_list		*previous;

	tmp = lst;
	while (tmp && tmp->next && tmp->next->next)
	{
		if (ft_nbdiff(tmp->content, tmp->next->content) > 0)
			return (0);
		previous = tmp;
		tmp = tmp->next;
	}
	if ((ft_nbdiff(tmp->content, tmp->next->content) > 0) &&
			ft_nbdiff(tmp->next->content, previous->content) > 0)
		return (1);
	else
		return (0);
}

static void		ft_savelines(t_list **output, int count, t_list **a, t_list **b)
{
	int			ra_or_rra;
	t_list		*tmp;

	ra_or_rra = 0;
	tmp = a[0];
	while (tmp && tmp->next && count)
	{
		if (ft_nbdiff(tmp->content, ft_lstmin(a[0])) == 0)
			count = 0;
		else
			ra_or_rra++;
		tmp = tmp->next;
	}
	if (ra_or_rra <= (ft_lstlen(a[0]) / 2))
	{
		while (--ra_or_rra >= 0)
			ft_add_instr("ra", a, b, output);
	}
	else
	{
		ra_or_rra = ft_lstlen(a[0]) - ra_or_rra;
		while (--ra_or_rra >= 0)
			ft_add_instr("rra", a, b, output);
	}
}

static t_byte	ft_almost_sort(t_list **a, t_list **b, t_list **output)
{
	t_list		*tmp;
	char		*intruder;
	t_byte		count;

	tmp = a[0];
	count = 0;
	while (tmp && tmp->next)
	{
		if (ft_nbdiff(tmp->content, tmp->next->content) > 0 && !count)
		{
			intruder = tmp->next->content;
			count++;
		}
		else if (ft_nbdiff(tmp->content, tmp->next->content) > 0 && count)
			return (0);
		tmp = tmp->next;
	}
	if (count == 1 && !ft_nbdiff(intruder, ft_lstmin(a[0])))
		ft_savelines(output, count, a, b);
	return (1);
}

void			ft_check_almost_sort(t_list **a, t_list **b, t_list **output)
{
	if (!ft_list_is_sort(a[0]) && ft_lstlen(a[0]) > 3)
	{
		if (ft_list_is_sort(a[0]->next) &&
				(ft_nbdiff(a[0]->content, a[0]->next->next->content) < 0))
			ft_add_instr("sa", a, b, output);
		else if (ft_end_swap(a[0]))
		{
			ft_add_instr("rra", a, b, output);
			ft_add_instr("rra", a, b, output);
			ft_add_instr("sa", a, b, output);
			ft_add_instr("ra", a, b, output);
			ft_add_instr("ra", a, b, output);
		}
		else if (!ft_list_is_sort(a[0]))
			ft_almost_sort(a, b, output);
	}
	ft_sort3_a(a, output, 0);
}
