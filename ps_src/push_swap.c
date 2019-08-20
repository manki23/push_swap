/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:21 by manki             #+#    #+#             */
/*   Updated: 2019/08/20 17:32:13 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			ft_add_instruction(char *in, t_list **a, t_list **b, t_list **out)
{
	ft_apply_instruction(in, a, b);
	ft_lsadd(out, in, ft_strlen(in) + 1);
}

char		*ft_get_pivot(t_list *a)
{
	long long	median;

	median = (ft_atoll(ft_lstmin(a)) + ft_atoll(ft_lstmax(a))) / 2;
	return (ft_lltoa(median));
}

static void			ft_sort3_a(t_list a[], t_list **output)
{
	while (ft_lstlen(a) == 3 && !ft_list_is_sort(a))
	{
		if (ft_nbdiff(ft_lstmax(a), a->content) == 0 &&
				ft_list_is_sort(a->next))
			ft_add_instruction("ra", &a, NULL, output);
		else if (ft_nbdiff(a->content, a->next->content) < 0)
			ft_add_instruction("rra", &a, NULL, output);
		else if ((ft_nbdiff(a->content, a->next->content) > 0 &&
					(ft_nbdiff(ft_lstmin(a), a->next->content) == 0)) ||
				ft_list_is_reverse_sort(a))
			ft_add_instruction("sa", &a, NULL, output);
	}
	if (ft_lstlen(a) == 2 && !ft_list_is_sort(a))
		ft_add_instruction("sa", &a, NULL, output);
}

static void		ft_quicksort(t_list a[], t_list b[], t_list **output)
{
	t_list	**tab;
	int		len;
	t_list	*tmp;
	int		i;

	len = ft_lstlen(a);
	tab = (t_list **)malloc(sizeof(t_list *) * len);
	tmp = a;
	i = -1;
	while (++i < len)
	{
		tab[i] = tmp;
		tmp = tmp->next;
	}
	if (!ft_list_is_sort(a) && ft_lstlen(a) > 3)
		ft_sort_a(a, b, output);
	else
		ft_sort3_a(a, output);
	ft_list_print(*output, "\n");
	while (--len >= 0)
		ft_lstdelone(&tab[len]);
	free(tab);
	ft_lstdel(output);
}

int		main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	t_list	*output;

	ac--;
	av++;
	b = NULL;
	output = NULL;
	if (ac && ft_check_arg(ac, av, &a))
		ft_quicksort(a, b, &output);
	else if (ac)
	{
		ft_lstdel(&a);
		return (ft_error("Error", 2));
	}
	return (0);
}
