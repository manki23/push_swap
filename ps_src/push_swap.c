/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:21 by manki             #+#    #+#             */
/*   Updated: 2019/08/23 13:00:57 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_push_swap_display(t_list *output, t_byte *opt)
{
	while (output)
	{
		if (opt[1] && (!ft_strcmp(output->content, "sa") ||
					!ft_strcmp(output->content, "sb")))
			ft_putstr(_PURPLE);
		else if (opt[1] && (!ft_strcmp(output->content, "pa") ||
					!ft_strcmp(output->content, "pb")))
			ft_putstr(_CYAN);
		else if (opt[1] && (!ft_strcmp(output->content, "ra") ||
					!ft_strcmp(output->content, "rb")))
			ft_putstr(_YELLOW);
		else if (opt[1] && (!ft_strcmp(output->content, "rra") ||
					!ft_strcmp(output->content, "rrb")))
			ft_putstr(_BLUE);
		else if (opt[1])
			ft_putstr(_GREEN);
		write(1, output->content, output->content_size);
		ft_putendl(_END);
		output = output->next;
		if (opt[2])
			usleep(100000);
	}
}

static void		ft_quicksort(t_list a[], t_list b[], t_list **output, t_byte *o)
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
	ft_push_swap_display(*output, o);
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
	t_byte	*opt;

	ac--;
	av++;
	b = NULL;
	output = NULL;
	opt = ft_memalloc(3);
	if (ac && ft_check_arg(ac, av, &a, &opt))
		ft_quicksort(a, b, &output, opt);
	else if (ac)
		ft_error("Error", 2);
	ft_strdel((char **)&opt);
	return (0);
}
