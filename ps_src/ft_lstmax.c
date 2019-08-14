/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:28:51 by manki             #+#    #+#             */
/*   Updated: 2019/08/14 18:34:29 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char		*ft_lstmax(t_list **lst)
{
	t_list	*tmp;
	char	*max;

	tmp = lst[0];
	if (tmp)
	{
		max = tmp->content;
		tmp = tmp->content;
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
