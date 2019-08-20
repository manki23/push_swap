/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_almost_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:42:56 by manki             #+#    #+#             */
/*   Updated: 2019/08/20 19:46:26 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_add_instr(char *in, t_list **a, t_list **b, t_list **out)
{
	ft_apply_instruction(in, a, b);
	ft_lsadd(out, in, ft_strlen(in) + 1);
}

static void		ft_sort3_a(t_list **a, t_list **output)
{
	while (ft_lstlen(a[0]) == 3 && !ft_list_is_sort(a[0]))
	{
		if (ft_nbdiff(ft_lstmax(a[0]), a[0]->content) == 0 &&
				ft_list_is_sort(a[0]->next))
			ft_add_instr("ra", a, NULL, output);
		else if (ft_nbdiff(a[0]->content, a[0]->next->content) < 0)
			ft_add_instr("rra", a, NULL, output);
		else if ((ft_nbdiff(a[0]->content, a[0]->next->content) > 0 &&
					(ft_nbdiff(ft_lstmin(a[0]), a[0]->next->content) == 0)) ||
				ft_list_is_reverse_sort(a[0]))
			ft_add_instr("sa", a, NULL, output);
	}
	if (ft_lstlen(a[0]) == 2 && !ft_list_is_sort(a[0]))
		ft_add_instr("sa", a, NULL, output);
}

static t_byte	ft_almost_sort(t_list *lst)
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

static void		ft_sort_five(t_list **a, t_list **b, t_list **output)
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
	ft_sort3_a(a, output);
	ft_add_instr("pa", a, b, output);
	if (ft_nbdiff(a[0]->content, a[0]->next->content) > 0)
		ft_add_instr("ra", a, b, output);
	ft_add_instr("pa", a, b, output);
	if (ft_nbdiff(a[0]->content, a[0]->next->content) > 0)
		ft_add_instr("ra", a, b, output);
}

void			ft_check_almost_sort(t_list **a, t_list **b, t_list **output)
{

	if (!ft_list_is_sort(a[0]) && ft_lstlen(a[0]) > 3)
	{
		if (ft_lstlen(a[0]) == 5)
			ft_sort_five(a, b, output);
		else if (ft_list_is_sort(a[0]->next) &&
				(ft_nbdiff(a[0]->content, a[0]->next->next->content) < 0))
			ft_add_instr("sa", a, b, output);
		else if (ft_almost_sort(a[0]))
		{
			ft_add_instr("rra", a, b, output);
			ft_add_instr("rra", a, b, output);
			ft_add_instr("sa", a, b, output);
			ft_add_instr("ra", a, b, output);
			ft_add_instr("ra", a, b, output);
		}
	}
	else
		ft_sort3_a(a, output);
}
