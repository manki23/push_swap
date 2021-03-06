/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:19:38 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:07:30 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (s)
	{
		i = -1;
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	}
}
