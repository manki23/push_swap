/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:40:58 by manki             #+#    #+#             */
/*   Updated: 2019/08/14 17:41:00 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

void		ft_list_print(t_list list[], char *separator)
{
	size_t	ret;

	ret = 0;
	while (list)
	{
		write(1, list->content, list->content_size);
		ft_putstr(separator);
		ret += list->content_size;
		list = list->next;
	}
}
