/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:13:33 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/19 15:38:11 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_next(t_list **stack_a, int max, int min)
{
	t_list *lst;
	int i;
	int j;

	lst = *stack_a;
	i = 0;
	j = 1;
	while (lst && (lst->rank > max || lst->rank < min))
	{
		i++;
		lst = lst->next;
	}
	if (!lst)
		return (0);
	while (lst)
	{
		j++;
		if (lst->rank <= max && lst->rank >= min)
			j = 1;
		lst = lst->next;
	}
	if (j >= i)
		return (1);
	else
		return (-1);
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

void	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	int interval;
	int size;

	interval = 0;
	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) >= 22)
	{
		push_interval(stack_a, stack_b, interval + 21, interval);
		interval += 22;
	}
	push_interval(stack_a, stack_b, size - 1, interval);
	back_sort(stack_a, stack_b, size - 1);
}
