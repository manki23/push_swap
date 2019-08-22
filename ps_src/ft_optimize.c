/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:40:44 by manki             #+#    #+#             */
/*   Updated: 2019/08/22 20:28:21 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_byte		ft_cmp(char *str1, char *str2, char *ref1, char *ref2)
{
	if (!ft_strcmp(str1, ref1) && !ft_strcmp(str2, ref2))
		return (1);
	else if (!ft_strcmp(str1, ref2) && !ft_strcmp(str2, ref1))
		return (1);
	else
		return (0);
}

static t_byte		ft_cut_pointless(t_list *previous, t_list **ref)
{
	t_list	*del;

	del = ref[0];
	if (previous)
	{
		ref[0] = ref[0]->next->next;
		previous->next = ref[0];
	}
	else
		ref[0] = ref[0]->next->next;
	del->next->next = NULL;
	ft_lstdel(&del);
	return (1);
}

static t_byte		ft_combine(t_list *previous, t_list **ref, char *str)
{
	t_list		*replace;

	ft_cut_pointless(previous, ref);
	replace = ft_lstnew(str, ft_strlen(str) + 1);
	if (previous)
	{
		previous->next = replace;
		replace->next = ref[0];
	}
	else
	{
		replace->next = ref[0];
		ref[0] = replace;
	}
	return (1);
}

void			ft_optimize(t_list **output)
{
	t_list		*tmp;
	t_byte		modif;
	t_list		*previous;

	modif = 1;
	previous = NULL;
	while (modif)
	{
		modif = 0;
		tmp = output[0];
		while (tmp && tmp->next)
		{
			if (ft_cmp(tmp->content, tmp->next->content, "pa", "pb") ||
					ft_cmp(tmp->content, tmp->next->content, "ra", "rra") ||
					ft_cmp(tmp->content, tmp->next->content, "rb", "rrb"))
				modif += ft_cut_pointless(previous, &tmp);
			else if (ft_cmp(tmp->content, tmp->next->content, "sa", "sb"))
				modif += ft_combine(previous, &tmp, "ss");
			else if (ft_cmp(tmp->content, tmp->next->content, "rra", "rrb"))
				modif += ft_combine(previous, &tmp, "rrr");
			else if (ft_cmp(tmp->content, tmp->next->content, "ra", "rb"))
				modif += ft_combine(previous, &tmp, "rr");
			previous = tmp;
			tmp = tmp->next;
		}
	}
}
