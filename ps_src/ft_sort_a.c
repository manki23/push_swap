/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:56:23 by manki             #+#    #+#             */
/*   Updated: 2019/08/20 17:32:43 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_sort3_complicated_a(t_list a[], t_list b[], t_list **output)
{
	while (ft_lstlen(a) == 3 && !ft_list_is_sort(a))
	{
		if (ft_nbdiff(ft_lstmax(a), a->content) == 0 ||
				ft_nbdiff(ft_lstmax(a), a->next->next->content) == 0)
			ft_add_instruction("sa", &a, &b, output);
		else
		{
			ft_add_instruction("pb", &a, &b, output);
			ft_add_instruction("sa", &a, &b, output);
			ft_add_instruction("pa", &a, &b, output);
		}
	}
	if (ft_lstlen(a) == 2 && !ft_list_is_sort(a))
		ft_add_instruction("sa", &a, NULL, output);
}

void			ft_sort_a(t_list a[], t_list b[], t_list **output)
{
	char	*pivot;
	int		ra_count;
	int		i;

	ra_count = 0;
	i = ft_lstlen(a);
	if (i >	3)
	{
		pivot = ft_get_pivot(a);
		while (i > 0)
		{
			if (ft_nbdiff(a->content, pivot) > 0)
			{
				ft_add_instruction("ra", &a, &b, output);
				ra_count++;
			}
			else
				ft_add_instruction("pb", &a, &b, output);
			i--;
		}
		while (a && --ra_count >= 0)
			ft_add_instruction("rra", &a, &b, output);
		ft_strdel(&pivot);
	}
	if (!ft_list_is_sort(a) && ft_lstlen(a) > 3)
		ft_sort_a(a, NULL, output);
	ft_sort3_complicated_a(a, b, output);
	if (!ft_list_is_reverse_sort(b))
		ft_reverse_sort_b(NULL, b, output);
	else
		while (b)
			ft_add_instruction("pa", &a, &b, output);
}
