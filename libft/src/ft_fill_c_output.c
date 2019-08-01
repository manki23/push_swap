/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_c_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:33:19 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 16:45:03 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

static char		*ft_fill_output(t_option opt, char *arg, size_t *size)
{
	char	*output;

	if (opt.width > (int)size[0])
	{
		output = ft_memalloc(opt.width + 1);
		arg = ft_realloc(arg, opt.width + 1);
		ft_memset(output, ' ', opt.width - size[0]);
		if ((opt.option & ZERO) && !(opt.option & MINUS))
			ft_tr(output, ' ', '0');
		if (opt.option & MINUS)
			output = ft_charcat(arg[0], output, opt.width - size[0]);
		else
			output = ft_strcat(output, arg);
		size[0] += opt.width - size[0];
		ft_strdel(&arg);
	}
	else
		output = ft_realloc(arg, size[0] + 1);
	return (output);
}

char			*ft_fill_c_output(t_option opt, va_list *ap, size_t *size)
{
	unsigned char	*arg;
	char			*output;

	arg = ft_memalloc(2);
	if (opt.flag & H_POURCENT)
		arg[0] = '%';
	else
		arg[0] = va_arg(*ap, int);
	size[0] = 1;
	output = ft_fill_output(opt, (char *)arg, size);
	return (output);
}
