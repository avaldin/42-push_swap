/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:29:12 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/31 09:49:23 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	what_rotate_a(int p_a, t_list **stack_a)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (p_a > size / 2)
	{
		while (p_a++ < size)
			reverse_rotate_a(stack_a);
	}
	else if (p_a)
	{
		while (p_a-- > 0)
			rotate_a(stack_a);
	}
}

void	separation(t_list **stack_a, t_list **stack_b, int pivot)
{
	while ((*stack_a)->rank != pivot)
	{
		if ((*stack_a)->rank == ((*stack_a)->next)->rank + 1)
			swap_a(stack_a);
		if ((*stack_a)->rank < pivot)
			push_b(stack_a, stack_b);
		else if ((*stack_a)->rank != pivot)
			rotate_a(stack_a);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	median(t_list **stack)
{
	t_list	*lst;
	int		max;
	int		min;

	max = 0;
	min = 2147483647;
	lst = *stack;
	while (lst)
	{
		if (lst->rank > max)
			max = lst->rank;
		if (lst->rank < min)
			min = lst->rank;
		lst = lst->next;
	}
	return (min + (max - min) / 2);
}
