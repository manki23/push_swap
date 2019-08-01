/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 09:33:44 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:10:33 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	str = ft_strlowcase(str);
	i = 0;
	if (ft_isalnum(str[0]))
		str[0] = ft_toupper(str[0]);
	while (str[++i])
	{
		if (!ft_isalnum(str[i - 1]) && ft_isalnum(str[i]))
			str[i] = ft_toupper(str[i]);
	}
	return (str);
}
