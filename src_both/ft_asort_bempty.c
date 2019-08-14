/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asort_bempty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:35:20 by manki             #+#    #+#             */
/*   Updated: 2019/08/14 15:05:00 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long			ft_nbdiff(char *nb1, char *nb2)
{
	long long	a;
	long long	b;

	a = ft_atoll(nb1);
	b = ft_atoll(nb2);
	return (a - b);
}

t_byte				ft_asort_bempty(t_list *a, t_list *b)
{
	t_list	*tmp;

	if (!b)
	{
		tmp = a;
		while (tmp && tmp->next)
		{
			if (ft_nbdiff(tmp->content, tmp->next->content) > 0)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}
