/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:39:24 by manki             #+#    #+#             */
/*   Updated: 2019/09/01 19:50:10 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_byte		ft_check_duplicates(t_list **a, char *av, int len)
{
	t_list		*tmp;

	tmp = *a;
	if (tmp)
	{
		while (tmp)
		{
			if (!ft_strcmp(av, tmp->content) ||
					(ft_atoll(av) == ft_atoll(tmp->content)))
				return (0);
			tmp = tmp->next;
		}
		ft_lsadd(a, av, len + 1);
	}
	return (1);
}

static t_byte		ft_delwordtable(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

static t_byte		ft_check_option(char *input, t_byte *opt)
{
	t_byte		ret;

	ret = 1;
	if (!opt[0] && !ft_strcmp(input, "-v"))
		opt[0] = 1;
	else if (!opt[1] && !ft_strcmp(input, "-c"))
		opt[1] = 1;
	else if (!opt[2] && !ft_strcmp(input, "-s"))
	{
		opt[3] = 1;
		opt[2] = 1;
	}
	else if (!opt[2] && ft_strlen(input) == 3 && input[0] == '-'
			&& input[1] == 's' && ft_isdigit(input[2]))
	{
		opt[2] = 1;
		opt[3] = input[2] - '0';
	}
	else
		ret = 0;
	return (ret);
}

static t_byte		ft_check_one(char **tab, t_list **a, t_coord c, t_byte **op)
{
	int			len;
	long long	nb;

	nb = ft_atoll(tab[c.i]);
	len = ft_strlen(tab[c.i]);
	if (len <= 11 && (ft_str_is_numeric(tab[c.i]) || (tab[c.i][0] == '-' &&
					ft_str_is_numeric(&tab[c.i][1]))) &&
			(nb >= INT_MIN && nb <= INT_MAX) && ft_strcmp(tab[c.i], "-") != 0 &&
			ft_strcmp(tab[c.i], "-0") != 0)
	{
		if (!a[0])
			a[0] = ft_lstnew(tab[c.i], len + 1);
		else if (!ft_check_duplicates(a, tab[c.i], len))
			return (0);
	}
	else if (!a[0])
		return (ft_check_option(tab[c.i], op[0]));
	else
		return (0);
	return (1);
}

t_byte				ft_check_arg(int ac, char *av[], t_list **a, t_byte **opt)
{
	t_coord		c;
	char		**tab;

	c.j = 0;
	while (c.j < ac)
	{
		tab = ft_split_whitespaces(av[c.j]);
		c.i = 0;
		while (tab[c.i])
		{
			if (!ft_check_one(tab, a, c, opt))
				return (ft_delwordtable(tab));
			c.i++;
		}
		c.j++;
		ft_delwordtable(tab);
	}
	return (1);
}
