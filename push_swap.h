/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:13:44 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 19:04:49 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_mode
{
	DEFAULT,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH
}	t_mode;

typedef struct s_flags
{
	t_mode	mode;
	int		bench;
}	t_flags;

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_operations
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_operations;

typedef struct s_stacks
{
	t_list			*a;
	t_list			*b;
	t_operations	operations;
}	t_stacks;

// Input Handling
t_mode	get_mode(char *str);
char	**build_args(char **argv);
void	check_args(char **args);
void	init_flags(t_flags *flags);
void	init_stacks(t_stacks *stacks);
void	parse_args(char **args, t_flags *flags, t_stacks *stacks);
void	assign_index(t_list *stack);
void	free_args(char **args);
void	free_stacks(t_stacks *stacks);

// Operations
void	sa(t_stacks *stacks, int record, int print);
void	sb(t_stacks *stacks, int record, int print);
void	ss(t_stacks *stacks, int record, int print);
void	pa(t_stacks *stacks, int record, int print);
void	pb(t_stacks *stacks, int record, int print);
void	ra(t_stacks *stacks, int record, int print);
void	rb(t_stacks *stacks, int record, int print);
void	rr(t_stacks *stacks, int record, int print);
void	rra(t_stacks *stacks, int record, int print);
void	rrb(t_stacks *stacks, int record, int print);
void	rrr(t_stacks *stacks, int record, int print);

// Libft Functions
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(int, int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
