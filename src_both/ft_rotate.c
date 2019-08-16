/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:36:16 by manki             #+#    #+#             */
/*   Updated: 2019/08/15 16:17:25 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_ra(t_list **a, t_list **b)
{
	t_list *tmp;
	t_list *first;

	(void)b;
	tmp = a[0];
	first = a[0];
	if (tmp && tmp->next)
	{
		a[0] = a[0]->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
	}
}

void		ft_rb(t_list **a, t_list **b)
{
	t_list *tmp;
	t_list *first;

	(void)a;
	tmp = b[0];
	first = b[0];
	if (tmp && tmp->next)
	{
		b[0] = b[0]->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
	}
}

void		ft_rr(t_list **a, t_list **b)
{
	ft_ra(a, b);
	ft_rb(a, b);
}
