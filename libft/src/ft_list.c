/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:32:07 by manki             #+#    #+#             */
/*   Updated: 2019/08/16 15:31:53 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	if (!(fresh = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		if (!(fresh->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	fresh->next = NULL;
	return (fresh);
}

void		ft_lsadd(t_list **list, void const *content, size_t c_size)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, c_size);
	}
	else
		list[0] = ft_lstnew(content, c_size);
}

int			ft_lstlen(t_list *list)
{
	int		len;
	t_list	*tmp;

	len = 0;
	if (list)
	{
		tmp = list;
		while (tmp)
		{
			tmp = tmp->next;
			len++;
		}
	}
	return (len);
}

size_t		ft_lst_content_size(t_list *list)
{
	size_t	ret;
	t_list	*tmp;

	ret = 0;
	tmp = list;
	while (tmp)
	{
		ret += tmp->content_size;
		tmp = tmp->next;
	}
	return (ret);
}

size_t		ft_lstprint(t_list list[])
{
	size_t	ret;

	ret = 0;
	while (list)
	{
		write(1, list->content, list->content_size);
		ret += list->content_size;
		list = list->next;
	}
	return (ret);
}
