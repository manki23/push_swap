/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:21 by manki             #+#    #+#             */
/*   Updated: 2019/08/14 14:32:11 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_display(t_list *a, t_list *b)
{
	ft_printf("-----------------------\n");
	ft_printf("list a = [ ");
	ft_lstprint(a);
	ft_printf(" ]\nlist b = [ ");
	ft_lstprint(b);
	ft_printf(" ]\n");
}

static char		*ft_get_pivot(t_list *a)
{
	t_list	*tmp;

	tmp = a;
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

static void		ft_sort(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp && tmp->next && !ft_asort_bempty(*a, NULL))
	{
		if (ft_nbdiff(tmp->content, tmp->next->content) > 0)
		{
			ft_sa(a, b);
			ft_putendl("sa");
		}
		else
		{
			ft_pb(a, b);
			ft_putendl("pb");
		}
		tmp = tmp->next;
	}
	while (ft_asort_bempty(*a, NULL) && b[0])
	{
		ft_pa(a, b);
		ft_putendl("pa");
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
		while (!ft_asort_bempty(a, b))
		{
			pivot = ft_get_pivot(a);
			if (pivot)
			{
			}
			ft_sort(&a, &b);
		}
		ft_lstdel(&a);
	}
	else if (ac)
	{
		ft_lstdel(&a);
		return (ft_error("Error", 2));
	}
	return (0);
}
