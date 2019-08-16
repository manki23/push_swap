/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:39:24 by manki             #+#    #+#             */
/*   Updated: 2019/08/16 16:56:01 by manki            ###   ########.fr       */
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
			if (!ft_strcmp(av, tmp->content))
				return (0);
			tmp = tmp->next;
		}
		ft_lsadd(a, av, len + 1);
	}
	return (1);
}

static void			ft_delwordtable(char **str)
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
}

t_byte				ft_check_arg(int ac, char *av[], t_list **a)
{
	int			i;
	int			j;
	int			len;
	long long	nb;
	char		**tab;

	j = 0;
	while (j < ac)
	{
		tab = ft_split_whitespaces(av[j]);
		i = 0;
		while (tab[i])
		{
			nb = ft_atoll(tab[i]);
			len = ft_strlen(tab[i]);
			if ((ft_str_is_numeric(tab[i]) || (tab[i][0] == '-' &&
			ft_str_is_numeric(&tab[i][1]))) && !((len == 10 ||
			(tab[i][0] == '-' && len == 11)) && (nb < INT_MIN || nb > INT_MAX)))
			{
				if (j == 0 && i == 0)
					a[0] = ft_lstnew(tab[i], len + 1);
				else if (!ft_check_duplicates(a, tab[i], len))
				{
					ft_delwordtable(tab);
					return (0);
				}
			}
			else
			{
				ft_delwordtable(tab);
				return (0);
			}
			i++;
		}
		j++;
		ft_delwordtable(tab);
	}
	return (1);
}
