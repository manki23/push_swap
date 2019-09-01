/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:56:23 by manki             #+#    #+#             */
/*   Updated: 2019/09/01 19:15:55 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char			*ft_get_pivot(t_list *a)
{
	long long	median;

	median = (ft_atoll(ft_lstmin(a)) + ft_atoll(ft_lstmax(a))) / 2;
	return (ft_lltoa(median));
}

void			ft_sort3_complicated_a(t_list a[], t_list b[], t_list **output)
{
	while (ft_lstlen(a) == 3 && !ft_list_is_sort(a))
	{
		if (ft_nbdiff(ft_lstmax(a), a->content) == 0 ||
				ft_nbdiff(ft_lstmax(a), a->next->next->content) == 0)
			ft_add_instr("sa", &a, &b, output);
		else
		{
			ft_add_instr("pb", &a, &b, output);
			ft_add_instr("sa", &a, &b, output);
			ft_add_instr("pa", &a, &b, output);
		}
	}
	if (ft_lstlen(a) == 2 && !ft_list_is_sort(a))
		ft_add_instr("sa", &a, NULL, output);
}

static void		ft_split(t_list **a, t_list **b, t_list **output)
{
	int		i;
	int		ra_count;
	char	*pivot;

	ra_count = 0;
	pivot = ft_get_pivot(a[0]);
	i = ft_lstlen(a[0]);
	while (i > 0)
	{
		if (ft_nbdiff(a[0]->content, pivot) > 0)
		{
			ft_add_instr("ra", a, b, output);
			ra_count++;
		}
		else
			ft_add_instr("pb", a, b, output);
		i--;
	}
	while (a[0] && --ra_count >= 0)
		ft_add_instr("rra", a, b, output);
	ft_strdel(&pivot);
}

void			ft_sort_a(t_list a[], t_list b[], t_list **output)
{
	if (ft_lstlen(a) > 3)
		ft_split(&a, &b, output);
	if (!ft_list_is_sort(a) && ft_lstlen(a) > 3)
		ft_sort_a(a, NULL, output);
	ft_sort3_complicated_a(a, b, output);
	if (!ft_list_is_reverse_sort(b))
		ft_reverse_sort_b(NULL, b, output);
	else
		while (b)
			ft_add_instr("pa", &a, &b, output);
}
