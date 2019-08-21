/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_is_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:03:24 by manki             #+#    #+#             */
/*   Updated: 2019/08/21 12:03:29 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_byte		ft_list_is_reverse_sort(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (ft_nbdiff(tmp->content, tmp->next->content) < 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_byte		ft_list_is_sort(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (ft_nbdiff(tmp->content, tmp->next->content) > 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
