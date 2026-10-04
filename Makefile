# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siooi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/19 15:20:12 by siooi             #+#    #+#              #
#    Updated: 2026/10/04 16:48:27 by siooi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
HEADER	= push_swap.h

BONUS_NAME	= checker
BONUS_HEADER	= checker.h

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

MAIN	= main

INPUT	= $(addprefix input/, \
		flags \
		parse \
		check \
		stacks \
		index)

BENCHMARK	= $(addprefix benchmark/, \
		init \
		print)

ALGORITHMS	= $(addprefix algorithms/, \
		sort \
		sort_utils \
		fixed_sort \
		simple \
		simple_utils \
		simple_cost \
		simple_rotation \
		medium)

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
		ft_putchar_fd \
	  	ft_putendl_fd \
		ft_putnbr_fd \
	  	ft_putstr_fd \
	  	ft_split \
	  	ft_strcmp \
	  	ft_strdup \
	  	ft_strjoin \
	  	ft_strlen)

BONUS	= $(addprefix bonus/, \
		main \
		input) \
	$(addprefix algorithms/, sort_utils)

SRCS	= $(addsuffix .c, $(MAIN) $(INPUT) $(BENCHMARK) $(ALGORITHMS) $(OPERATIONS) $(LIBFT))
OBJS	= $(SRCS:.c=.o)

BONUS_SRCS	= $(addsuffix .c, $(BONUS) $(INPUT) $(OPERATIONS) $(LIBFT))
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

bonus/%.o	: bonus/%.c $(BONUS_HEADER) $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g $(OBJS) -o $(NAME)

bonus	: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g $(BONUS_OBJS) -o $(BONUS_NAME)

clean	:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean	: clean
	${RM} $(NAME) $(BONUS_NAME)

re	: fclean all

.PHONY	: all bonus clean fclean re
