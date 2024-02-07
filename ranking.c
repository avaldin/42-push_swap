/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:09:49 by avaldin           #+#    #+#             */
/*   Updated: 2023/12/27 09:35:48 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranking(t_list **stack)
{
	t_list	*lst;
	int		i;
	int		temp_num;
	int		temp;

	lst = *stack;
	i = 0;
	temp = -2147483648;
	while (i < ft_lstsize(*stack))
	{
		lst = *stack;
		temp_num = 2147483647;
		while (lst)
		{
			if ((lst->num <= temp_num) && (lst->num > temp || i == 0))
			{
				lst->rank = i;
				temp_num = lst->num;
			}
			lst = lst->next;
		}
		i++;
		temp = temp_num;
	}
}
