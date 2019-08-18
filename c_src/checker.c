/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:23:53 by manki             #+#    #+#             */
/*   Updated: 2019/08/18 17:09:09 by manki            ###   ########.fr       */
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

static void			ft_apply_instruction(char *in, t_list **a, t_list **b)
{
	if (!(ft_strcmp(in, "sa")))
		ft_sa(a, b);
	else if (!(ft_strcmp(in, "sb")))
		ft_sb(a, b);
	else if (!(ft_strcmp(in, "ss")))
		ft_ss(a, b);
	else if (!(ft_strcmp(in, "pa")))
		ft_pa(a, b);
	else if (!(ft_strcmp(in, "pb")))
		ft_pb(a, b);
	else if (!(ft_strcmp(in, "ra")))
		ft_ra(a, b);
	else if (!(ft_strcmp(in, "rb")))
		ft_rb(a, b);
	else if (!(ft_strcmp(in, "rr")))
		ft_rr(a, b);
	else if (!(ft_strcmp(in, "rra")))
		ft_rra(a, b);
	else if (!(ft_strcmp(in, "rrb")))
		ft_rrb(a, b);
	else if (!(ft_strcmp(in, "rrr")))
		ft_rrr(a, b);
	ft_putendl(in);
	ft_ps_display(*a, *b);
}

int					main(int ac, char *av[])
{
	char	*in;
	t_list	*a;
	t_list	*b;

	av++;
	ac--;
	b = NULL;
	if (ac && ft_check_arg(ac, av, &a))
	{
		while (get_next_line(0, &in) == 1 && ft_strlen(in))
		{
			if (!ft_check_instruction(in))
				return (ft_error("Error", 2));
			ft_apply_instruction(in, &a, &b);
			ft_strdel(&in);
		}
		ft_strdel(&in);
		if (ft_asort_bempty(a, b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_lstdel(&a);
		ft_lstdel(&b);
	}
	else if (ac)
	{
		ft_lstdel(&a);
		return (ft_error("Error", 2));
	}
	return (0);
}
