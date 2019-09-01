/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:02:45 by manki             #+#    #+#             */
/*   Updated: 2019/09/01 17:47:22 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_del(char *rr, t_list *previous, t_list *tmp)
{
	t_list		*to_del;
	t_list		*tmp2;

	to_del = previous->next;
	previous->next = tmp;
	while (to_del && !ft_strcmp(to_del->content, rr))
	{
		tmp2 = to_del;
		to_del = to_del->next;
		ft_lstdelone(&tmp2);
	}
}

static void		ft_replace_by_rb(t_list *previous, t_list *curser, int rb)
{
	t_list		*rb_lst;
	t_list		*tmp;
	t_list		*tmp2;

	rb_lst = NULL;
	if (rb > 0)
		rb_lst = ft_lstnew("rb", 3);
	while (--rb > 0)
		ft_lsadd(&rb_lst, "rb", 3);
	tmp = rb_lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = curser;
	if (previous && rb_lst)
	{
		tmp = previous->next;
		previous->next = rb_lst;
		while (tmp && !ft_strcmp(tmp->content, "rrb"))
		{
			tmp2 = tmp;
			tmp = tmp->next;
			ft_lstdelone(&tmp2);
		}
	}
}

void			ft_replace_rrb(t_list **output, t_list *a, t_list *b)
{
	t_list		*tmp;
	t_list		*previous;
	int			rb_or_rrb;

	tmp = output[0];
	previous = NULL;
	while (tmp && tmp->next && !(rb_or_rrb = 0))
	{
		if (ft_strcmp(tmp->content, "rrb") != 0)
		{
			ft_apply_instruction(tmp->content, &a, &b);
			previous = tmp;
			tmp = tmp->next;
		}
		while (tmp && !ft_strcmp(tmp->content, "rrb") && ++rb_or_rrb)
		{
			ft_apply_instruction(tmp->content, &a, &b);
			tmp = tmp->next;
		}
		if (rb_or_rrb > 0 && (rb_or_rrb > (ft_lstlen(b) / 2)))
			ft_replace_by_rb(previous, tmp, ft_lstlen(b) - rb_or_rrb);
		if (rb_or_rrb == ft_lstlen(b))
			ft_del("rrb", previous, tmp);
	}
}

static void		ft_replace_by_ra(t_list *previous, t_list *curser, int ra)
{
	t_list		*ra_lst;
	t_list		*tmp;
	t_list		*tmp2;

	ra_lst = NULL;
	if (ra > 0)
		ra_lst = ft_lstnew("ra", 3);
	while (--ra > 0)
		ft_lsadd(&ra_lst, "ra", 3);
	tmp = ra_lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = curser;
	if (previous && ra_lst)
	{
		tmp = previous->next;
		previous->next = ra_lst;
		while (tmp && !ft_strcmp(tmp->content, "rra"))
		{
			tmp2 = tmp;
			tmp = tmp->next;
			ft_lstdelone(&tmp2);
		}
	}
}

void			ft_replace_rra(t_list **output, t_list *a, t_list *b)
{
	t_list		*tmp;
	t_list		*previous;
	int			ra_or_rra;

	tmp = output[0];
	previous = NULL;
	while (tmp && tmp->next && !(ra_or_rra = 0))
	{
		if (ft_strcmp(tmp->content, "rra") != 0)
		{
			ft_apply_instruction(tmp->content, &a, &b);
			previous = tmp;
			tmp = tmp->next;
		}
		while (tmp && !ft_strcmp(tmp->content, "rra") && ++ra_or_rra)
		{
			ft_apply_instruction(tmp->content, &a, &b);
			tmp = tmp->next;
		}
		if (ra_or_rra > 0 && (ra_or_rra > (ft_lstlen(a) / 2)))
			ft_replace_by_ra(previous, tmp, ft_lstlen(a) - ra_or_rra);
		if (ra_or_rra == ft_lstlen(a))
			ft_del("rra", previous, tmp);
	}
}
