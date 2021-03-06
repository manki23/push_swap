/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:53:02 by manki             #+#    #+#             */
/*   Updated: 2019/08/18 16:16:13 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylibft.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*tmp;

	while (*alst)
	{
		free(alst[0]->content);
		alst[0]->content = NULL;
		tmp = alst[0];
		alst[0] = alst[0]->next;
		free(tmp);
		tmp = NULL;
	}
	free(*alst);
	*alst = NULL;
}

void	ft_lstdelone(t_list **alst)
{
	free(alst[0]->content);
	alst[0]->content = NULL;
	free(alst[0]);
	alst[0] = NULL;
}
