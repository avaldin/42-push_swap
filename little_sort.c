/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:39:10 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/24 11:36:30 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_part(t_list **stack_a, t_list **stack_b)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->rank;
	y = (*stack_a)->next->rank;
	z = (*stack_a)->next->next->rank;
	if (x < y && x < z && y > z)
	{
		rotate_a(stack_a);
		if ((*stack_b)->rank > (*stack_b)->next->rank)
			swap_both(stack_a, stack_b);
		else
			swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	if (x > y && y > z)
	{
		if ((*stack_b)->rank > (*stack_b)->next->rank)
			swap_both(stack_a, stack_b);
		else
			swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	sort_this_tree(t_list **stack_a, t_list **stack_b)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->rank;
	y = (*stack_a)->next->rank;
	z = (*stack_a)->next->next->rank;
	if (x < y && y > z && x > z)
		reverse_rotate_a(stack_a);
	if (x > y && x > z && y < z)
		rotate_a(stack_a);
	if (x > y && x < z && y < z)
	{
		if ((*stack_b)->rank > (*stack_b)->next->rank)
			swap_both(stack_a, stack_b);
		else
			swap_a(stack_a);
	}
	second_part(stack_a, stack_b);
}

void	threesort(t_list **stack_a)
{
	if ((*stack_a)->rank == 2)
	{
		rotate_a(stack_a);
		if ((*stack_a)->rank == 1)
			swap_a(stack_a);
	}
	else if ((*stack_a)->rank == 1)
		swap_a(stack_a);
	else
	{
		rotate_a(stack_a);
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	fivesort(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if ((*stack_a)->next->next)
		sort_this_tree(stack_a, stack_b);
	else if ((*stack_a)->rank > (*stack_a)->next->rank)
		swap_a(stack_a);
	if ((*stack_b)->rank > (*stack_b)->next->rank)
		swap_b(stack_b);
	if (!(*stack_b)->rank)
		push_a(stack_a, stack_b);
	while (*stack_b)
	{
		if ((*stack_a)->rank == (*stack_b)->rank + 1)
			push_a(stack_a, stack_b);
		else if (ft_lstlast(*stack_a)->rank + 1 == (*stack_b)->rank)
			push_a(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	what_rotate_a(find_a_rank(stack_a, 0), stack_a);
}

bool	little_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;

	lst = *stack_a;
	while (lst)
	{
		if (sorted(stack_a, lst->rank))
			return (true);
		else
			false_sorted(stack_a);
		lst = lst->next;
	}
	if (ft_lstsize(*stack_a) == 3)
		threesort(stack_a);
	else
		fivesort(stack_a, stack_b);
	return (true);
}
