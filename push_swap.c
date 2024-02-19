/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:30:34 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/17 14:17:24 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	false_sorted(t_list **stack_a)
{
	t_list	*lst;

	lst = *stack_a;
	while (lst)
	{
		lst->sorted = false;
		lst = lst->next;
	}
}

void	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return ;
	if (argc == 2)
		argv = ft_split(argv[1], ' ', &argc);
	stack_a = NULL;
	stack_b = NULL;
	arg_process(argc, argv, &stack_a);
	ranking(&stack_a);
	false_sorted(&stack_a);
	if (!argv[0])
		ft_freeee(argv, argc);
	if (!stack_a || check_rep(&stack_a) || ft_lstsize(stack_a) < argc - 1)
		write(STDERR_FILENO, "Error\n", 6);
	ft_sorting(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
