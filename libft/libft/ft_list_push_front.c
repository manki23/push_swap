/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:40:41 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:20:59 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

void	ft_list_push_front(t_list **list, char *content, size_t c_size)
{
	t_list		*tmp;
	t_list		*list_copy;

	tmp = ft_lstnew(content, c_size);
	if (list && tmp)
	{
		list_copy = *list;
		tmp->next = list_copy;
		*list = tmp;
	}
}
