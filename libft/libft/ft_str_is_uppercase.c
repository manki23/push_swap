/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 09:30:29 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:10:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

int		ft_str_is_uppercase(char *str)
{
	int		res;
	int		i;

	res = 1;
	i = -1;
	while (res && str[++i])
		res = ft_isupper(str[i]);
	return (res);
}
