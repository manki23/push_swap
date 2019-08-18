/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:21 by manki             #+#    #+#             */
/*   Updated: 2019/08/18 18:55:16 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			ft_instruction(char *in, t_list **a, t_list **b, t_list **out)
{
	if (!ft_strcmp(in, "sa"))
		ft_sa(a, b);
	else if (!ft_strcmp(in, "sb"))
		ft_sb(a, b);
	else if (!ft_strcmp(in, "ss"))
		ft_ss(a, b);
	else if (!ft_strcmp(in, "ra"))
		ft_ra(a, b);
	else if (!ft_strcmp(in, "rb"))
		ft_rb(a, b);
	else if (!ft_strcmp(in, "rr"))
		ft_rr(a, b);
	else if (!ft_strcmp(in, "pa"))
		ft_pa(a, b);
	else if (!ft_strcmp(in, "pb"))
		ft_pb(a, b);
	else if (!ft_strcmp(in, "rra"))
		ft_rra(a, b);
	else if (!ft_strcmp(in, "rrb"))
		ft_rrb(a, b);
	else if (!ft_strcmp(in, "rrr"))
		ft_rrr(a, b);
	ft_lsadd(out, in, ft_strlen(in) + 1);
		ft_putendl(in);
		if (a && b)
			ft_ps_display(*a, *b);
		else if (a)
			ft_ps_display(*a, NULL);
		else if (b)
			ft_ps_display(NULL, *b);

}

char		*ft_get_pivot(t_list *a)
{
	long long	median;

	median = (ft_atoll(ft_lstmin(a)) + ft_atoll(ft_lstmax(a))) / 2;
	return (ft_lltoa(median));
}

void			ft_sort3_a(t_list a[], t_list **output)
{
	while (ft_lstlen(a) == 3 && !ft_list_is_sort(a))
	{
		if (ft_nbdiff(ft_lstmax(a), a->content) == 0 &&
				ft_list_is_sort(a->next))
			ft_instruction("ra", &a, NULL, output);
		else if (ft_nbdiff(a->content, a->next->content) < 0)
			ft_instruction("rra", &a, NULL, output);
		else if ((ft_nbdiff(a->content, a->next->content) > 0 &&
					(ft_nbdiff(ft_lstmin(a), a->next->content) == 0)) ||
				ft_list_is_reverse_sort(a))
			ft_instruction("sa", &a, NULL, output);
	}
	if (ft_lstlen(a) == 2 && !ft_list_is_sort(a))
		ft_instruction("sa", &a, NULL, output);
}

int				ft_reverse_sort3_b(t_list **a, t_list **b, t_list **output)
{
	int		rb_count;
	int		b_len;

	rb_count = 0;
	while (ft_lstlen(b[0]) == 3 && !ft_list_is_reverse_sort(b[0]))
	{
		if (ft_nbdiff(b[0]->content, ft_lstmax(b[0])) == 0)
			ft_instruction("pa", a, b, output);
		else if (ft_nbdiff(b[0]->next->content, ft_lstmax(b[0])) == 0)
			ft_instruction("sb", a, b, output);
		else if (ft_list_is_sort(b[0]) || ((ft_nbdiff(b[0]->content,
				b[0]->next->content) > 0) &&
				(ft_nbdiff(b[0]->next->content, b[0]->next->next->content) < 0)))
		{
			ft_instruction("rb", a, b, output);
			rb_count++;
		}
	}
	b_len = ft_lstlen(b[0]);
	if (b_len == 2 && !ft_list_is_reverse_sort(b[0]))
		ft_instruction("sb", a, b, output);
	while ((--b_len < 3) && (b_len >= rb_count))
	{
		ft_instruction("pa", a, b, output);
	}
	while ((b_len <= 3) && (--rb_count >= 0))
		ft_instruction("rrb", a, b, output);
	return(rb_count);
}

void			ft_reverse_sort_b(t_list a[], t_list b[], t_list **output)
{
	char	*pivot;
	int		rb_count;

	pivot = ft_get_pivot(b);
	rb_count = 0;
	while (ft_lstlen(b) > 3)
	{
		if (ft_nbdiff(b->content, pivot) > 0)
			ft_instruction("pa", &a, &b, output);
		else
		{
			rb_count++;
			ft_instruction("rb", &a, &b, output);
		}
		ft_sort3_a(a, output);
	}
	// sort b <= 3
	rb_count += ft_reverse_sort3_b(&a, &b, output);
	if (ft_lstlen(b) > 3 && !ft_list_is_reverse_sort(b))
		ft_reverse_sort_b(NULL, b, output);
	else
	{
		while (--rb_count >= 0)
			ft_instruction("rrb", &a, &b, output);
		while (b)
			ft_instruction("pa", &a, &b, output);
	}
	ft_strdel(&pivot);
}

void			ft_sort_a(t_list a[], t_list b[], t_list **output)
{
	char	*pivot;
	int		i;

	i = ft_lstlen(a);
	pivot = ft_get_pivot(a);
	ft_sort3_a(a, output);
	if (!ft_list_is_sort(a))
	{
		while (i > 0)
		{
			if (ft_nbdiff(a->content, pivot) > 0)
				ft_instruction("ra", &a, &b, output);
			else
				ft_instruction("pb", &a, &b, output);
			i--;
		}
		if (ft_lstlen(a) <= 3 && !ft_list_is_sort(a))
			ft_sort3_a(a, output);
		else if (!ft_list_is_sort(a))
			ft_sort_a(a, NULL, output);
		ft_sort3_a(a, output);
		if (!ft_list_is_reverse_sort(b))
			ft_reverse_sort_b(NULL, b, output);
		else
		{
			i = ft_lstlen(b);
			while (--i >= 0)
				ft_instruction("rrb", &a, &b, output);
			while (b)
				ft_instruction("pa", &a, &b, output);
		}
	}
	ft_strdel(&pivot);
}

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
	if (!ft_list_is_sort(a))
		ft_sort_a(a, b, output);
	ft_list_print(*output, "\n");
	while (--len >= 0)
		ft_lstdelone(&tab[len]);
	free(tab);
	ft_lstdel(output);
}

int		main(int ac, char *av[])
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
	{
		ft_lstdel(&a);
		return (ft_error("Error", 2));
	}
	return (0);
}

/*void			ft_reverse_sort_b(t_list a[], t_list b[], t_list **output)
  {
  char	*pivot;
  int		i;

  i = ft_lstlen(b);
  pivot = ft_get_pivot(b);
  while (i > 0 && !ft_list_is_reverse_sort(b) && ft_lstlen(b) > 2)
  {
  if (ft_nbdiff(b->content, pivot) > 0)
  ft_instruction("pa", &a, &b, output);
  else
  ft_instruction("rb", &a, &b, output);
  i--;
  }
  ft_sort3_a(a, output);
  ft_reverse_sort3_b(b, output);
  if (!ft_list_is_sort(a))
  ft_sort_a(a, NULL, output);
  if (!ft_list_is_reverse_sort(b))
  ft_reverse_sort_b(NULL, b, output);
  else
  {
  i = ft_lstlen(b);
  while (--i >= 0)
  ft_instruction("rrb", &a, &b, output);
  while (b)
  ft_instruction("pa", &a, &b, output);
  }
  ft_strdel(&pivot);
  }
  */
