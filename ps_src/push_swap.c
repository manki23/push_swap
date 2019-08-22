/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:21 by manki             #+#    #+#             */
/*   Updated: 2019/08/22 17:53:58 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_quicksort(t_list a[], t_list b[], t_list **output)
{
	t_list	**tab;
	int		len;
	t_list	*tmp;
	int		i;

	len = ft_lstlen(a);
	tab = (t_list **)malloc(sizeof(t_list *) * len);
	tmp = a;
	i = -1;
	while (++i < len)
	{
		tab[i] = tmp;
		tmp = tmp->next;
	}
	ft_check_almost_sort(&a, &b, output);
	if (!ft_list_is_sort(a))
		ft_sort_a(a, b, output);
	ft_optimize(output);
	ft_list_print(*output, "\n");
	while (--len >= 0)
		ft_lstdelone(&tab[len]);
	free(tab);
	ft_lstdel(output);
}

int				main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	t_list	*output;

	ac--;
	av++;
	b = NULL;
	output = NULL;
	if (ac && ft_check_arg(ac, av, &a))
		ft_quicksort(a, b, &output);
	else if (ac)
		ft_error("Error", 2);
	return (0);
}
