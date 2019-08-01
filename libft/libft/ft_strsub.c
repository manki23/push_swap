/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:30:27 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:18:07 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	i;

	if (!s || !(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start + i] && ((start + i) < (start + len)))
	{
		fresh[i] = s[start + i];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
