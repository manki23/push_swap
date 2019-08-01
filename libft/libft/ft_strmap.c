/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:44:19 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:14:47 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (!s || !(fresh = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		fresh[i] = f((char)s[i]);
	fresh[i] = '\0';
	return (fresh);
}
