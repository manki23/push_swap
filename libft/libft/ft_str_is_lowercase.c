/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 09:19:23 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:09:09 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

int		ft_str_is_lowercase(char *str)
{
	int		i;
	int		res;

	res = 1;
	i = -1;
	while (res && str[++i])
		res = ft_islower(str[i]);
	return (res);
}
