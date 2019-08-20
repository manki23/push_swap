/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_is_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   lsty: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:24:11 lsty manki             #+#    #+#             */
/*   Updated: 2019/08/16 15:47:55 by manki            ###   ########.fr       */
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
