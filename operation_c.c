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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_the_next(t_list **stack_a, int max, int min)
{
	t_list	*lst;
	int		i;
	int		j;

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
