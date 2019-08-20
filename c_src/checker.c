/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:23:53 by manki             #+#    #+#             */
/*   Updated: 2019/08/20 17:08:41 by manki            ###   ########.fr       */
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
		if (ft_list_is_sort(a) && !b)
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
