/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:49:05 by manki             #+#    #+#             */
/*   Updated: 2019/08/02 15:40:31 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_rra(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*tmp;

	(void)b;
	tmp = a[0];
	if (tmp)
	{
		last = tmp->next;
		while (tmp->next && last->next)
		{
			tmp = tmp->next;
			last = last->next;
		}
		last->next = a[0];
		tmp->next = NULL;
		a[0] = last;
	}
}

void		ft_rrb(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*tmp;

	(void)a;
	tmp = b[0];
	if (tmp)
	{
		last = tmp->next;
		while (tmp->next && last->next)
		{
			tmp = tmp->next;
			last = last->next;
		}
		last->next = b[0];
		tmp->next = NULL;
		b[0] = last;
	}
}

void		ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a, b);
	ft_rrb(a, b);
}
