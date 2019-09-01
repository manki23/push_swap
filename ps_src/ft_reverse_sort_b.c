/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_sort_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:56:55 by manki             #+#    #+#             */
/*   Updated: 2019/09/01 18:24:30 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_reverse_sort3_b(t_list **a, t_list **b, t_list **output)
{
	while (ft_lstlen(b[0]) == 3 && !ft_list_is_reverse_sort(b[0]))
	{
		if (ft_nbdiff(b[0]->content, ft_lstmax(b[0])) == 0)
			ft_add_instr("pa", a, b, output);
		else if (ft_nbdiff(b[0]->next->content, ft_lstmax(b[0])) == 0)
			ft_add_instr("sb", a, b, output);
		else if (ft_list_is_sort(b[0]) ||
				((ft_nbdiff(b[0]->content, b[0]->next->content) > 0) &&
			(ft_nbdiff(b[0]->next->content, b[0]->next->next->content) < 0)))
		{
			ft_add_instr("rb", a, b, output);
			ft_add_instr("sb", a, b, output);
			if (ft_list_is_reverse_sort(b[0]))
				ft_add_instr("pa", a, b, output);
			ft_add_instr("pa", a, b, output);
			ft_add_instr("rrb", a, b, output);
		}
	}
	if (ft_lstlen(b[0]) == 2 && !ft_list_is_reverse_sort(b[0]))
		ft_add_instr("sb", a, b, output);
	while (b[0] && ft_list_is_reverse_sort(b[0]))
		ft_add_instr("pa", a, b, output);
}

static void		ft_split(t_list **a, t_list **b, t_list **output)
{
	char	*pivot;
	int		rb_count;
	int		i;

	rb_count = 0;
	i = ft_lstlen(b[0]);
	pivot = ft_get_pivot(b[0]);
	while (--i >= 0)
	{
		if (ft_nbdiff(b[0]->content, pivot) > 0)
			ft_add_instr("pa", a, b, output);
		else
		{
			rb_count++;
			ft_add_instr("rb", a, b, output);
		}
	}
	while (b[0] && --rb_count >= 0)
		ft_add_instr("rrb", a, b, output);
	ft_strdel(&pivot);
}

void			ft_reverse_sort_b(t_list a[], t_list b[], t_list **output)
{
	if (ft_lstlen(b) > 3)
		ft_split(&a, &b, output);
	if (!ft_list_is_sort(a))
		ft_sort_a(a, NULL, output);
	ft_reverse_sort3_b(&a, &b, output);
	if (ft_lstlen(b) > 3 && !ft_list_is_reverse_sort(b))
		ft_reverse_sort_b(NULL, b, output);
	else
		while (b)
			ft_add_instr("pa", &a, &b, output);
}
