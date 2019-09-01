/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:23:53 by manki             #+#    #+#             */
/*   Updated: 2019/09/01 19:49:57 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_byte	ft_check_instruction(char *input)
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

static void		ft_output(t_list **a, t_list **b, char **in, t_byte *opt)
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

static void		ft_display_input(char in[], t_byte *opt)
{
	if (opt[1] && (!ft_strcmp(in, "sa") ||
				!ft_strcmp(in, "sb")))
		ft_putstr(_PURPLE);
	else if (opt[1] && (!ft_strcmp(in, "pa") ||
				!ft_strcmp(in, "pb")))
		ft_putstr(_CYAN);
	else if (opt[1] && (!ft_strcmp(in, "ra") ||
				!ft_strcmp(in, "rb")))
		ft_putstr(_YELLOW);
	else if (opt[1] && (!ft_strcmp(in, "rra") ||
				!ft_strcmp(in, "rrb")))
		ft_putstr(_BLUE);
	else if (opt[1])
		ft_putstr(_GREEN);
	ft_putstr(in);
	ft_putendl(_END);
}

static void		ft_checker_display(t_list **a, t_list **b, t_byte *op, char *in)
{
	if (op[0])
		ft_display_input(in, op);
	if (op[1] && ft_list_is_sort(a[0]) && ft_list_is_reverse_sort(b[0]))
		ft_putstr(_GREEN);
	else if (op[1])
		ft_putstr(_YELLOW);
	if (op[0])
		ft_ps_display(*a, *b);
	if (op[1])
		ft_putstr(_END);
	if (op[2])
		usleep(USLEEP_DEFAULT_VALUE * op[3]);
}

int				main(int ac, char *av[])
{
	char	*in;
	t_list	*a;
	t_list	*b;
	t_byte	*opt;

	av++;
	a = NULL;
	b = NULL;
	opt = ft_memalloc(4);
	if (--ac && ft_check_arg(ac, av, &a, &opt))
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
