/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:05:51 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:16:51 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	swap;
	char	b;
	char	*s;

	i = 0;
	len = ft_strlen(str);
	s = ft_memalloc(len + 1);
	s = ft_memcpy(s, str, len);
	while (--len > i)
	{
		swap = s[i];
		b = s[len];
		s[i] = b;
		s[len] = swap;
		i++;
	}
	return (s);
}
