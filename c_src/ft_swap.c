/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:49:00 by manki             #+#    #+#             */
/*   Updated: 2019/08/02 14:27:22 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_sa(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	(void)b;
	tmp = a[0];
	if (tmp && tmp->next)
	{
		a[0] = tmp->next;
		tmp2 = a[0]->next;
		tmp->next = tmp2;
		a[0]->next = tmp;
	}
}

void		ft_sb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	(void)a;
	tmp = b[0];
	if (tmp && tmp->next)
	{
		b[0] = tmp->next;
		tmp2 = b[0]->next;
		tmp->next = tmp2;
		b[0]->next = tmp;
	}
}

void		ft_ss(t_list **a, t_list **b)
{
	ft_sa(a, b);
	ft_sb(a, b);
}
