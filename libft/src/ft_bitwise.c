/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:16:24 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 16:44:47 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

void		ft_add_bit(t_byte *tab, t_byte bit, t_byte at)
{
	if (bit)
		tab[at / 8] |= 1 << (at & 7);
	else
		tab[at / 8] &= ~(1 << (at & 7));
}

t_byte		ft_read(t_byte tab[], t_byte at)
{
	return ((tab[at / 8] & (1 << (at & 7))) >> (at & 7));
}

t_byte		ft_fill_opt(t_byte *dst, char src, char tab[])
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (src == tab[i])
		{
			ft_add_bit(dst, 1, i);
			return (1);
		}
	}
	return (0);
}
