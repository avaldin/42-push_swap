/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:04:17 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/19 15:15:31 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **arg_a)
{
	t_list	*lst;

	if (ft_lstsize(*arg_a) > 1)
	{
		lst = *arg_a;
		*arg_a = (*arg_a)->next;
		lst->next = NULL;
		ft_lstadd_back(arg_a, lst);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **arg_b)
{
	t_list	*lst;

	if (ft_lstsize(*arg_b) > 1)
	{
		lst = *arg_b;
		*arg_b = (*arg_b)->next;
		lst->next = NULL;
		ft_lstadd_back(arg_b, lst);
		write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_list **arg_a)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;

	lst_a = *arg_a;
	i = ft_lstsize(lst_a) - 1;
	while (i-- > 1)
		*arg_a = (*arg_a)->next;
	lst_b = *arg_a;
	*arg_a = (*arg_a)->next;
	(*arg_a)->next = lst_a;
	lst_b->next = NULL;
}

void	reverse_rotate_a(t_list **arg_a)
{
	if (ft_lstsize(*arg_a) > 1)
	{
		reverse_rotate(arg_a);
		write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}
