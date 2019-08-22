/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:02:41 by manki             #+#    #+#             */
/*   Updated: 2019/08/22 20:30:27 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_apply_instruction(char *in, t_list **a, t_list **b)
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
}
