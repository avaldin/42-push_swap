/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:24:06 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/20 18:09:10 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	int				num;
	int				rank;
	struct s_list	*next;
}					t_list;

void	push_swap(int argc, char **argv);
void	arg_process(int argc, char **argv, t_list **first);
bool	check_rep(t_list **arg);
t_list	*ft_lstnew(int num);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c, int *argc);
char	**ft_freeee(char **str, int n);
void	ranking(t_list **stack);
void	swap_a(t_list **arg_a);
void	swap_b(t_list **arg_a);
void	swap_both(t_list **arg_a, t_list **arg_b);
void	push_a(t_list **arg_a, t_list **arg_b);
void	push_b(t_list **arg_a, t_list **arg_b);
void	rotate_a(t_list **arg_a);
void	rotate_b(t_list **arg_a);
void	reverse_rotate(t_list **arg_a);
void	reverse_rotate_a(t_list **arg_a);
void	reverse_rotate_b(t_list **stack_b);
void	ft_sorting(t_list **stack_a, t_list **stack_b);
void	threesort(t_list **stack_a);
void	little_sort(t_list **stack_a, t_list **stack_b);
bool	sorted(t_list **stack_a);
int		find_the_next(t_list **stack_a, int max, int min);

#endif
