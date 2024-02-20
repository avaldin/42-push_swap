/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:13:33 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/20 17:52:32 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_list **stack_a)
{
	t_list	*lst;
	t_list	*lst_next;

	lst = *stack_a;
	lst_next = lst;
	while (lst->rank)
		lst = lst->next;
	if (lst->next)
		lst_next = lst->next;
	while (lst_next->rank)
	{
		if (lst->rank + 1 != lst_next->rank)
			return (false);
		lst = lst_next;
		lst_next = lst->next;
		if (!lst_next)
			lst_next = *stack_a;
	}
	return (true);
}

void	push_interval(t_list **stack_a, t_list **stack_b, int max, int min)
{
	int		dir;

	dir = find_the_next(stack_a, max, min);
	while (dir)
	{
		if (dir > 0)
			while ((*stack_a)->rank > max || (*stack_a)->rank < min)
				rotate_a(stack_a);
		else
			while ((*stack_a)->rank > max || (*stack_a)->rank < min)
				reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		dir = find_the_next(stack_a, max, min);
	}
}

void	back_sort(t_list **stack_a, t_list **stack_b, int max)
{
	int	dir;

	dir = find_the_next(stack_b, max, max);
	while (dir)
	{
		if (dir > 0)
			while ((*stack_b)->rank > max || (*stack_b)->rank < max)
				rotate_b(stack_b);
		else
			while ((*stack_b)->rank > max || (*stack_b)->rank < max)
				reverse_rotate_b(stack_b);
		push_a(stack_a, stack_b);
		max--;
		dir = find_the_next(stack_b, max, max);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	interval;

	interval = 0;
	while (ft_lstsize(*stack_a) >= 22)
	{
		push_interval(stack_a, stack_b, interval + 21, interval);
		interval += 22;
	}
	push_interval(stack_a, stack_b, size - 1, interval);
	back_sort(stack_a, stack_b, size - 1);
}

void	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (sorted(stack_a))
	{
		if (find_the_next(stack_a, 0, 0) > 0)
			while ((*stack_a)->rank)
				rotate_a(stack_a);
		else
			while ((*stack_a)->rank)
				reverse_rotate_a(stack_a);
	}
	else if (size < 6)
		little_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, size);
}
