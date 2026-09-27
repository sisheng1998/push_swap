# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siooi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/19 15:20:12 by siooi             #+#    #+#              #
#    Updated: 2026/09/27 18:27:52 by siooi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
HEADER	= push_swap.h

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

MAIN	= main

ALGORITHMS	= $(addprefix algorithms/, \
		sort \
		sort_utils \
		fixed_sort \
		simple \
		simple_utils \
		simple_cost \
		simple_rotation)

INPUT	= $(addprefix input/, \
		flags \
		parse \
		check \
		stacks \
		index)

OPERATIONS	= $(addprefix operations/, \
		swap \
		push \
		rotate \
		reverse_rotate)

LIBFT	= $(addprefix libft/, \
		ft_atol \
		ft_isdigit \
	  	ft_lstadd_back \
	  	ft_lstiter \
	  	ft_lstlast \
	  	ft_lstnew \
	  	ft_lstsize \
	  	ft_putendl_fd \
	  	ft_putstr_fd \
	  	ft_split \
	  	ft_strcmp \
	  	ft_strdup \
	  	ft_strjoin \
	  	ft_strlen)

SRCS	= $(addsuffix .c, $(MAIN) $(ALGORITHMS) $(INPUT) $(OPERATIONS) $(LIBFT))
OBJS	= $(SRCS:.c=.o)

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g $(OBJS) -o $(NAME)

clean	:
	${RM} ${OBJS}

fclean	: clean
	${RM} $(NAME)

re	: fclean all

.PHONY	: all bonus clean fclean re
