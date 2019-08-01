/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:30:38 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:04:19 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fresh;
	t_list		*tmp;

	if (lst)
	{
		fresh = f(lst);
		tmp = fresh;
		lst = lst->next;
		while (lst)
		{
			tmp->next = f(lst);
			lst = lst->next;
			tmp = tmp->next;
		}
		return (fresh);
	}
	return (NULL);
}
