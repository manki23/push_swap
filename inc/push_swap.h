/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:33:14 by manki             #+#    #+#             */
/*   Updated: 2019/08/20 17:15:14 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/mylibft.h"

void		ft_sa(t_list **a, t_list **b);
void		ft_sb(t_list **a, t_list **b);
void		ft_ss(t_list **a, t_list **b);

void		ft_pa(t_list **a, t_list **b);
void		ft_pb(t_list **a, t_list **b);

void		ft_ra(t_list **a, t_list **b);
void		ft_rb(t_list **a, t_list **b);
void		ft_rr(t_list **a, t_list **b);

void		ft_rra(t_list **a, t_list **b);
void		ft_rrb(t_list **a, t_list **b);
void		ft_rrr(t_list **a, t_list **b);

void		ft_ps_display(t_list *a, t_list *b);

t_byte		ft_check_arg(int ac, char *av[], t_list **a);

long long	ft_nbdiff(char *nb1, char *nb2);

void		ft_apply_instruction(char *in, t_list **a, t_list **b);

void		ft_add_instruction(char *in, t_list **a, t_list **b, t_list **out);
char		*ft_get_pivot(t_list *a);

t_byte		ft_list_is_reverse_sort(t_list lst[]);
t_byte		ft_list_is_sort(t_list lst[]);
char		*ft_lstmax(t_list *lst);
char		*ft_lstmin(t_list *lst);

void		ft_sort_a(t_list a[], t_list b[], t_list **output);
void		ft_reverse_sort_b(t_list a[], t_list b[], t_list **output);

#endif
