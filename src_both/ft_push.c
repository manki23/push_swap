/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:28:08 by manki             #+#    #+#             */
/*   Updated: 2019/08/02 14:35:44 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = b[0];
	if (tmp)
	{
		b[0] = b[0]->next;
		tmp->next = a[0];
		a[0] = tmp;
	}
}

void		ft_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = a[0];
	if (tmp)
	{
		a[0] = a[0]->next;
		tmp->next = b[0];
		b[0] = tmp;
	}
}
