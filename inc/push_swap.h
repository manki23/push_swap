/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:33:14 by manki             #+#    #+#             */
/*   Updated: 2019/09/03 14:26:48 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/mylibft.h"

# define _GREY "\033[30m"
# define _RED "\033[31m"
# define _GREEN "\033[32m"
# define _YELLOW "\033[33m"
# define _BLUE "\033[34m"
# define _PURPLE "\033[35m"
# define _CYAN "\033[36m"
# define _WHITE "\033[37m"
# define _END "\033[0m"

# define USLEEP_DEFAULT_VALUE 100000

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

t_byte		ft_check_arg(int ac, char *av[], t_list **a, t_byte **opt);

long long	ft_nbdiff(char *nb1, char *nb2);

void		ft_apply_instruction(char *in, t_list **a, t_list **b);

void		ft_check_almost_sort(t_list **a, t_list **b, t_list **output);
void		ft_add_instr(char *in, t_list **a, t_list **b, t_list **out);

void		ft_sort3_a(t_list **a, t_list **output, t_byte bol);
void		ft_sort3_complicated_a(t_list a[], t_list b[], t_list **output);
void		ft_sort_four(t_list **a, t_list **b, t_list **output, t_byte bol);
void		ft_sort_five(t_list **a, t_list **b, t_list **output, t_byte bol);
void		ft_sort_six(t_list **a, t_list **b, t_list **output);
void		ft_sort_seven(t_list **a, t_list **b, t_list **output);

void		ft_optimize(t_list **output);

void		ft_replace_rra(t_list **output, t_list *a, t_list *b);
void		ft_replace_rrb(t_list **output, t_list *a, t_list *b);

t_byte		ft_list_is_reverse_sort(t_list lst[]);
t_byte		ft_list_is_sort(t_list lst[]);
char		*ft_lstmax(t_list *lst);
char		*ft_lstmin(t_list *lst);

char		*ft_get_pivot(t_list *a);
void		ft_sort_a(t_list a[], t_list b[], t_list **output);
void		ft_reverse_sort_b(t_list a[], t_list b[], t_list **output);

#endif
