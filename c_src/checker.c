/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:23:53 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 19:52:45 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_byte		ft_check_arg(int ac, char *av[])
{
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	while (j < ac)
	{
		if (ft_str_is_numeric(av[j]))
			ret += 1;
		j++;
	}
	if (ret == ac)
		return (1);
	else
		return (0);
}

int					main(int ac, char *av[])
{
	char	*in;
	int		i;

	//ac--;
	av++;
	ac--;
	if (ft_check_arg(ac, av))
	{
		i = ac + 1;
		while (--i > 0)
		{
			get_next_line(0, &in);
		}
	}
	else
		ft_printf("Error\n");
	return (0);
}
