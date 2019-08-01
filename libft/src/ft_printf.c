/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:00:08 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 16:43:27 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

int				ft_strlentoc(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void		ft_analyze(char *ptr, t_list *out, va_list *ap)
{
	char	*ptr2;
	char	*content;
	size_t	size;

	while (ptr && ptr[0] == '%')
	{
		content = ft_conv(&ptr, ap, &size);
		if (size > 0)
		{
			ft_lsadd(&out, content, size);
			ft_strdel(&content);
		}
		if (!(ptr2 = ft_strchr(ptr, '%')))
			ft_lsadd(&out, ptr, ft_strlen(ptr));
		else
			ft_lsadd(&out, ptr, ft_strlen(ptr) - ft_strlen(ptr2));
		ptr = ptr2;
	}
	va_end(*ap);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;
	char		*ptr;
	t_list		*out;

	ret = 0;
	if (format && ((ret = ft_strlen(format)) > 0))
	{
		if (!(ptr = ft_strchr(format, '%')))
			ft_putstr(format);
		else
		{
			if (!(out = ft_lstnew((char *)format, ft_strlentoc(format, '%'))))
				return (-1);
			va_start(ap, format);
			ft_analyze(ptr, out, &ap);
			ret = ft_lstprint(out);
			ft_lstdel(&out);
		}
	}
	return (ret);
}
