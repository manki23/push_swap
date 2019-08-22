/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:39:24 by manki             #+#    #+#             */
/*   Updated: 2019/08/22 15:47:25 by manki            ###   ########.fr       */
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

static t_byte		ft_check_one(char **tab, int i, int j, t_list **a)
{
	int			len;
	long long	nb;

	nb = ft_atoll(tab[i]);
	len = ft_strlen(tab[i]);
	if (len <= 11 && (ft_str_is_numeric(tab[i]) || (tab[i][0] == '-' &&
					ft_str_is_numeric(&tab[i][1]))) &&
			(nb >= INT_MIN && nb <= INT_MAX) && ft_strcmp(tab[i], "-") != 0 &&
			ft_strcmp(tab[i], "-0") != 0)
	{
		if (j == 0 && i == 0)
			a[0] = ft_lstnew(tab[i], len + 1);
		else if (!ft_check_duplicates(a, tab[i], len))
			return (ft_delwordtable(tab));
	}
	else
		return (ft_delwordtable(tab));
	return (1);
}

t_byte				ft_check_arg(int ac, char *av[], t_list **a)
{
	int			i;
	int			j;
	char		**tab;

	j = 0;
	while (j < ac)
	{
		tab = ft_split_whitespaces(av[j]);
		i = 0;
		while (tab[i])
		{
			if (!ft_check_one(tab, i, j, a))
				return (0);
			i++;
		}
		j++;
		ft_delwordtable(tab);
	}
	return (1);
}
