/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:23:08 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/17 13:07:14 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_rank(t_list **stack, int rank)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = *stack;
	while (lst->rank != rank && lst->next)
	{
		i++;
		lst = lst->next;
	}
	if (lst->rank != rank)
		return (-1);
	return (i);
}

t_list	*lst_next(t_list *lst, t_list **stack_a)
{
	t_list	*lst_next;

	lst_next = lst;
	if (!lst_next->next)
		lst_next = *stack_a;
	else
		lst_next = lst_next->next;
	return (lst_next);
}
