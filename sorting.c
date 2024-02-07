/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:13:33 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/31 09:40:32 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	can_be_sorted(t_list **stack_a, t_list *lst)
{
	t_list	*lst_i;

	lst_i = *stack_a;
	while (lst_i->rank)
		lst_i = lst_next(lst_i, stack_a);
	while (lst_i != lst && lst_i->rank < lst->rank)
		lst_i = lst_next(lst_i, stack_a);
	if (lst_i != lst)
		return (false);
	lst_i = lst_next(lst_i, stack_a);
	while (lst_i->rank && lst_i->rank > lst->rank)
		lst_i = lst_next(lst_i, stack_a);
	if (lst_i->rank)
		return (false);
	return (true);
}

bool	sorted(t_list **stack_a, int pivot)
{
	bool	sorted;
	t_list	*lst;

	sorted = true;
	lst = *stack_a;
	while (lst->rank != pivot)
		lst = lst->next;
	lst->sorted = true;
	lst = lst_next(lst, stack_a);
	while (lst->rank != pivot)
	{
		if (can_be_sorted(stack_a, lst))
			lst->sorted = true;
		else
			sorted = false;
		lst = lst_next(lst, stack_a);
	}
	if (sorted)
		what_rotate_a(find_a_rank(stack_a, 0), stack_a);
	return (sorted);
}

void	back_sort(t_list **stack_a, t_list **stack_b)
{
	int	pivot;

	pivot = ft_lstlast(*stack_b)->rank;
	ft_lstlast(*stack_b)->sorted = 1;
	while ((*stack_b)->rank != pivot)
	{
		if ((*stack_b)->rank >= pivot)
		{
			push_a(stack_a, stack_b);
			if ((*stack_a)->rank == ((*stack_a)->next)->rank + 1)
				swap_a(stack_a);
		}
		else if ((*stack_b)->rank != pivot)
			rotate_b(stack_b);
	}
	push_a(stack_a, stack_b);
}

bool	recu_sort(t_list **stack_a, t_list **stack_b, t_list *lst)
{
	separation(stack_a, stack_b, lst->rank);
	push_b(stack_a, stack_b);
	while (ft_lstlast(*stack_a)->sorted == 0)
		reverse_rotate_a(stack_a);
	while (*stack_b)
		back_sort(stack_a, stack_b);
	sorted(stack_a, 0);
	if (sorted(stack_a, 0))
	{
		what_rotate_a(find_a_rank(stack_a, 0), stack_a);
		return (true);
	}
	else
	{
		while ((*stack_a)->sorted == 1)
			rotate_a(stack_a);
		lst = *stack_a;
		while ((lst->next)->sorted != 1)
			lst = lst->next;
		return (recu_sort(stack_a, stack_b, lst));
	}
}

bool	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;

	if (ft_lstsize(*stack_a) < 6)
		return (little_sort(stack_a, stack_b));
	what_rotate_a(find_a_rank(stack_a, median(stack_a)), stack_a);
	rotate_a(stack_a);
	separation(stack_a, stack_b, ft_lstlast(*stack_a)->rank);
	while (*stack_b)
		back_sort(stack_a, stack_b);
	if (sorted(stack_a, 0))
		return (true);
	while ((*stack_a)->sorted == 1)
		rotate_a(stack_a);
	lst = *stack_a;
	while ((lst->next)->sorted != 1)
		lst = lst->next;
	return (recu_sort(stack_a, stack_b, lst));
}
