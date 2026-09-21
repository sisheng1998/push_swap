# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siooi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/19 15:20:12 by siooi             #+#    #+#              #
#    Updated: 2026/09/20 19:03:59 by siooi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
HEADER	= push_swap.h

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

MAIN	= main

INPUT	= input/flags \
	  input/parse \
	  input/check \
	  input/stacks \
	  input/index

OPERATIONS	= operations/swap \
		  operations/push \
		  operations/rotate \
		  operations/reverse_rotate

LIBFT	= libft/ft_atol \
	  libft/ft_isdigit \
	  libft/ft_lstadd_back \
	  libft/ft_lstiter \
	  libft/ft_lstlast \
	  libft/ft_lstnew \
	  libft/ft_putendl_fd \
	  libft/ft_putstr_fd \
	  libft/ft_split \
	  libft/ft_strcmp \
	  libft/ft_strdup \
	  libft/ft_strjoin \
	  libft/ft_strlen

SRCS	= $(addsuffix .c, $(MAIN) $(INPUT) $(OPERATIONS) $(LIBFT))
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
