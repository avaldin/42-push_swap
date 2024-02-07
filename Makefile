# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:11:14 by avaldin           #+#    #+#              #
#    Updated: 2023/12/26 11:15:28 by avaldin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    =   arg_process.c\
			push_swap.c\
			lst_utils.c\
			ft_split.c\
			operation_a.c\
			operation_b.c\
			operation_c.c\
			sorting.c\
			ranking.c\
			recover_lst.c\
			little_sort.c\



OBJS    =    $(SRCS:.c=.o)


HEADER    =    push_swap.h

NAME    =    push_swap

CC        =    cc

FLAGS    =    -Wall -Wextra -Werror -g3

all			:	$(NAME)

%.o        :    %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME)    :    $(OBJS) Makefile
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

bonus    :
	@make SRCS="$(SRCS)"

clean    :
	rm -f $(OBJS)

fclean    :    clean
	rm -f $(NAME)

re        :    fclean all

.PHONY    :    all clean fclean re bonus