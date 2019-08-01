/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:20:40 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:14:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	if (size > 0)
	{
		i = -1;
		while ((++i < size - 1) && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
