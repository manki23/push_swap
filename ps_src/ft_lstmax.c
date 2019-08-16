/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:28:51 by manki             #+#    #+#             */
/*   Updated: 2019/08/16 16:03:11 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char		*ft_lstmax(t_list *lst)
{
	t_list	*tmp;
	char	*max;

	tmp = lst;
	if (tmp)
	{
		max = tmp->content;
		while (tmp)
		{
			if (ft_nbdiff(max, tmp->content) < 0)
				max = tmp->content;
			tmp = tmp->next;
		}
		return (max);
	}
	else
		return (NULL);
}

char		*ft_lstmin(t_list *lst)
{
	t_list	*tmp;
	char	*min;

	tmp = lst;
	if (tmp)
	{
		min = tmp->content;
		while (tmp)
		{
			if (ft_nbdiff(min, tmp->content) > 0)
				min = tmp->content;
			tmp = tmp->next;
		}
		return (min);
	}
	else
		return (NULL);
}
