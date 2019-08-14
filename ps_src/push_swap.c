/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:21 by manki             #+#    #+#             */
/*   Updated: 2019/08/14 18:36:31 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_display(t_list *a, t_list *b)
{
	ft_printf("-----------------------\n");
	ft_printf("list a = [ ");
	ft_list_print(a, " | ");
	ft_printf(" ]\nlist b = [ ");
	ft_list_print(b, " | ");
	ft_printf(" ]\n");
}

void			ft_instruction(char *in, t_list **a, t_list **b)
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
	ft_putendl(in);
//	ft_display(*a, *b);
}

static char		*ft_get_pivot(t_list **a)
{
	t_list	*tmp;

	tmp = a[0];
	while (tmp && tmp->next)
	{
		if (ft_nbdiff(tmp->content, tmp->next->content) > 0)
		{
			return (tmp->content);
		}
		tmp = tmp->next;
	}
	return ("sort");
}

void		ft_bogosort(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp && tmp->next && !ft_asort_bempty(*a, NULL))
	{
		if (ft_nbdiff(tmp->content, tmp->next->content) > 0)
			ft_instruction("sa", a, b);
		else
			ft_instruction("pb", a, b);
		tmp = tmp->next;
	}
	while (ft_asort_bempty(*a, NULL) && b[0])
		ft_instruction("pa", a, b);
}

void			ft_quicksort(t_list **a, t_list **b)
{
	char	*pivot;

	pivot = a[0]->content;
	while (pivot && !ft_asort_bempty(*a, NULL))
	{
		ft_instruction("ra", a, b);
		while (ft_nbdiff(a[0]->content, pivot) != 0)
		{
			if (ft_nbdiff(a[0]->content, pivot) > 0)
				ft_instruction("ra", a, b);
			else
				ft_instruction("pb", a, b);
		}
		//find out how to pick the next pivot//
		while (b[0])
		{
			if (b[0]->next && ft_nbdiff(b[0]->content, b[0]->next->content) < 0)
				ft_instruction("sb", a, b);
			ft_instruction("pa", a, b);
		}
	}
}

int		main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	char	*pivot;

	ac--;
	av++;
	b = NULL;
	if (ac && ft_check_arg(ac, av, &a))
	{
		//	while (!ft_asort_bempty(a, b))
		//	{
		pivot = ft_get_pivot(&a);
		//		if (pivot)
		//		{
		//		}
		//		ft_bogosort(&a, &b);
		//	}
		ft_quicksort(&a, &b);
		ft_lstdel(&a);
	}
	else if (ac)
	{
		ft_lstdel(&a);
		return (ft_error("Error", 2));
	}
	return (0);
}
