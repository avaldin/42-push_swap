/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:51:02 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/17 13:51:09 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **arg_a)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ft_lstsize(*arg_a) > 1)
	{
		lst_a = *arg_a;
		lst_b = lst_a->next;
		lst_a->next = lst_b->next;
		lst_b->next = lst_a;
		*arg_a = lst_b;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **arg_a)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ft_lstsize(*arg_a) > 1)
	{
		lst_a = *arg_a;
		lst_b = lst_a->next;
		lst_a->next = lst_b->next;
		lst_b->next = lst_a;
		*arg_a = lst_b;
		write(1, "sb\n", 3);
	}
}

void	swap_both(t_list **arg_a, t_list **arg_b)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ft_lstsize(*arg_a) > 1)
	{
		lst_a = *arg_a;
		lst_b = lst_a->next;
		lst_a->next = lst_b->next;
		lst_b->next = lst_a;
		*arg_a = lst_b;
	}
	if (ft_lstsize(*arg_b) > 1)
	{
		lst_a = *arg_b;
		lst_b = lst_a->next;
		lst_a->next = lst_b->next;
		lst_b->next = lst_a;
		*arg_b = lst_b;
	}
	write(1, "ss\n", 3);
}

void	push_a(t_list **arg_a, t_list **arg_b)
{
	t_list	*lst;

	if (ft_lstsize(*arg_b) > 0)
	{
		lst = *arg_b;
		*arg_b = lst->next;
		lst->next = *arg_a;
		*arg_a = lst;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **arg_a, t_list **arg_b)
{
	t_list	*lst;

	if (ft_lstsize(*arg_a) > 0)
	{
		lst = *arg_a;
		*arg_a = lst->next;
		lst->next = *arg_b;
		*arg_b = lst;
		write(1, "pb\n", 3);
	}
}
