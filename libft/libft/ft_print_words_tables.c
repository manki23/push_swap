/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:00:25 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:05:04 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

void	ft_print_words_tables(char **tab, char c)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putchar(c);
	}
}
