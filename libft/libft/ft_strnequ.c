/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:13:29 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:16:16 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && !ft_strncmp(s1, s2, n))
		return (1);
	else
		return (0);
}