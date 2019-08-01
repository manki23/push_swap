/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:58:34 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:15:07 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	if (!s || !(fresh = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		fresh[i] = f(i, s[i]);
	fresh[i] = '\0';
	return (fresh);
}
