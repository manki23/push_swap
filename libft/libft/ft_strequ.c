/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:07:17 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:12:21 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2 && !ft_strcmp(s1, s2))
		return (1);
	else
		return (0);
}