/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:23:53 by manki             #+#    #+#             */
/*   Updated: 2019/08/31 18:19:21 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_byte		ft_check_instruction(char *input)
{
	char	inst[11][4];
	int		i;

	ft_strncpy(inst[0], "sa", 3);
	ft_strncpy(inst[1], "sb", 3);
	ft_strncpy(inst[2], "ss", 3);
	ft_strncpy(inst[3], "pa", 3);
	ft_strncpy(inst[4], "pb", 3);
	ft_strncpy(inst[5], "ra", 3);
	ft_strncpy(inst[6], "rb", 3);
	ft_strncpy(inst[7], "rr", 3);
	ft_strncpy(inst[8], "rra", 4);
	ft_strncpy(inst[9], "rrb", 4);
	ft_strncpy(inst[10], "rrr", 4);
	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(inst[i], input))
			return (1);
		i++;
	}
	return (0);
}

static void			ft_output(t_list **a, t_list **b, char **in, t_byte *opt)
{
	if (ft_list_is_sort(a[0]) && !b[0])
	{
		if (opt[1])
			ft_putstr(_GREEN);
		ft_printf("OK\n");
	}
	else
	{
		if (opt[1])
			ft_putstr(_RED);
		ft_printf("KO\n");
	}
	if (opt[1])
		ft_putstr(_END);
	ft_lstdel(a);
	ft_lstdel(b);
	ft_strdel(in);
}

static void			ft_checker_display(t_list **a, t_list **b, t_byte *opt, char *in)
{
	if (opt[1])
		ft_putstr(_CYAN);
	if (opt[0])
		ft_putendl(in);
	if (opt[1])
		ft_putstr(_END);
	if (opt[1] && ft_list_is_sort(a[0]) && ft_list_is_reverse_sort(b[0]))
		ft_putstr(_GREEN);
	else if (opt[1])
		ft_putstr(_YELLOW);
	if (opt[0])
		ft_ps_display(*a, *b);
	if (opt[1])
		ft_putstr(_END);
	if (opt[2])
		usleep(USLEEP_DEFAULT_VALUE);
}

int					main(int ac, char *av[])
{
	char	*in;
	t_list	*a;
	t_list	*b;
	t_byte	*opt;

	av++;
	ac--;
	a = NULL;
	b = NULL;
	opt = ft_memalloc(3);
	if (ac && ft_check_arg(ac, av, &a, &opt))
	{
		while (get_next_line(0, &in) == 1 && ft_strlen(in))
		{
			if (!ft_check_instruction(in))
				ft_error("Error", 2);
			ft_apply_instruction(in, &a, &b);
			ft_checker_display(&a, &b, opt, in);
			ft_strdel(&in);
		}
		ft_output(&a, &b, &in, opt);
	}
	else if (ac)
		ft_error("Error", 2);
	ft_strdel((char **)&opt);
	return (0);
}
