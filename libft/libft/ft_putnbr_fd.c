/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:26:20 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:06:54 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

static void		ft_print(int n, int fd)
{
	if (n > -10 && n < 0)
		ft_putchar_fd('0' - n, fd);
	else if (n >= 0 && n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_print(n / 10, fd);
		ft_print(n % 10, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_print(n, fd);
}
