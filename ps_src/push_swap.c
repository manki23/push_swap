/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:21 by manki             #+#    #+#             */
/*   Updated: 2019/08/16 17:00:35 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			ft_instruction(char *in, t_list **a, t_list **b, t_list **out)
{
	if (!ft_strcmp(in, "sa"))
		ft_sa(a, b);
	else if (!ft_strcmp(in, "sb"))
		ft_sb(a, b);
	else if (!ft_strcmp(in, "ss"))
		ft_ss(a, b);
	else if (!ft_strcmp(in, "ra"))
		ft_ra(a, b);
	else if (!ft_strcmp(in, "rb"))
		ft_rb(a, b);
	else if (!ft_strcmp(in, "rr"))
		ft_rr(a, b);
	else if (!ft_strcmp(in, "pa"))
		ft_pa(a, b);
	else if (!ft_strcmp(in, "pb"))
		ft_pb(a, b);
	else if (!ft_strcmp(in, "rra"))
		ft_rra(a, b);
	else if (!ft_strcmp(in, "rrb"))
		ft_rrb(a, b);
	else if (!ft_strcmp(in, "rrr"))
		ft_rrr(a, b);
	ft_lsadd(out, in, ft_strlen(in) + 1);
//	ft_putendl(in);
//	ft_ps_display(*a, *b);
}

char		*ft_get_pivot(t_list *a)
{
	long long	median;

	median = (ft_atoll(ft_lstmin(a)) + ft_atoll(ft_lstmax(a))) / 2;
	return (ft_lltoa(median));
}

void			ft_reverse_sort_b(t_list *a, t_list *b, t_list **output)
{
	char	*pivot;
	int		i;

	i = ft_lstlen(b);
	pivot = ft_get_pivot(b);
	while (i > 0 && ft_lstlen(b) > 2)
	{
		if (ft_nbdiff(b->content, pivot) > 0)
			ft_instruction("pa", &a, &b, output);
		else
			ft_instruction("rb", &a, &b, output);
		i--;
	}
	if (!ft_list_is_sort(a))
		ft_sort_a(a, NULL, output);
	if (ft_lstlen(b) < 3 && !ft_list_is_reverse_sort(b))
		ft_instruction("sb", &a, &b, output);
	else if (ft_lstlen(b) >= 3 && !ft_list_is_reverse_sort(b))
		ft_reverse_sort_b(NULL, b, output);
	ft_strdel(&pivot);
}

void			ft_sort_a(t_list *a, t_list *b, t_list **output)
{
	char	*pivot;
	int		i;

	i = ft_lstlen(a);
	pivot = ft_get_pivot(a);
	while (i > 0 && ft_lstlen(a) > 2)
	{
		if (ft_nbdiff(a->content, pivot) > 0)
			ft_instruction("ra", &a, &b, output);
		else
			ft_instruction("pb", &a, &b, output);
		i--;
	}
	if (ft_lstlen(a) < 3 && !ft_list_is_sort(a))
		ft_instruction("sa", &a, &b, output);
	else if (ft_lstlen(a) >= 3 && !ft_list_is_sort(a))
	{
		ft_sort_a(a, NULL, output);
	}
	if (!ft_list_is_reverse_sort(b))
		ft_reverse_sort_b(NULL, b, output);
	else
	{
		i = ft_lstlen(b);
		ft_printf("b len = %d\n", i);
	ft_ps_display(a, b);
		ft_printf("pivot = %s\n", pivot);
		while (--i >= 0)
			ft_instruction("rrb", &a, &b, output);
		while (b)
			ft_instruction("pa", &a, &b, output);
	}
	ft_strdel(&pivot);
}

void			ft_quicksort(t_list *a, t_list *b, t_list **output)
{
	if (!ft_list_is_sort(a))
		ft_sort_a(a, b, output);
	ft_list_print(*output, "\n");
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
	{
		ft_quicksort(a, b, &output);
		ft_lstdel(&a);
	}
	else if (ac)
	{
		ft_lstdel(&a);
		return (ft_error("Error", 2));
	}
	return (0);
}
