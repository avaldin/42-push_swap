/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:10:12 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/17 14:10:09 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	my_atoi(char *str)
{
	int			i;
	long long	nbr;
	long long	sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while (str[i])
		i++;
	if (i > 11)
		return (2147483648);
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr * sign);
}

bool	not_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	check_rep(t_list **arg)
{
	t_list	*lst_i;
	t_list	*lst_j;
	int		i;
	int		j;

	lst_i = *arg;
	i = 0;
	while (lst_i)
	{
		lst_j = *arg;
		j = 0;
		while (lst_j)
		{
			if (lst_i->num == lst_j->num && i != j)
			{
				return (true);
			}
			j++;
			lst_j = lst_j->next;
		}
		i++;
		lst_i = lst_i->next;
	}
	return (false);
}

t_list	*lst_add(t_list **first, t_list *lst, long long check_int)
{
	if (!*first)
	{
		*first = ft_lstnew((int) check_int);
		return (*first);
	}
	else
	{
		lst->next = ft_lstnew((int) check_int);
		return (lst->next);
	}
}

void	arg_process(int argc, char **argv, t_list **first)
{
	int			i;
	t_list		*lst;
	long long	check_int;

	i = 0;
	lst = NULL;
	while (++i < argc && !(i > 1 && !lst))
	{
		if (not_num(argv[i]))
		{
			check_int = my_atoi(argv[i]);
			if (check_int < 2147483648 && check_int > -2147483649)
				lst = lst_add(first, lst, check_int);
		}
	}
}
