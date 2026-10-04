/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:39:07 by siooi             #+#    #+#             */
/*   Updated: 2026/10/03 16:06:38 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operation(char *name, int count, int fd)
{
	ft_putstr_fd(name, fd);
	ft_putstr_fd(":  ", fd);
	ft_putnbr_fd(count, fd);
	ft_putstr_fd("  ", fd);
}

static void	print_operations(t_operations operations, int fd)
{
	ft_putstr_fd("[bench] total_ops:  ", fd);
	ft_putnbr_fd(operations.total, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("[bench] ", fd);
	print_operation("sa", operations.sa, fd);
	print_operation("sb", operations.sb, fd);
	print_operation("ss", operations.ss, fd);
	print_operation("pa", operations.pa, fd);
	print_operation("pb", operations.pb, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("[bench] ", fd);
	print_operation("ra", operations.ra, fd);
	print_operation("rb", operations.rb, fd);
	print_operation("rr", operations.rr, fd);
	print_operation("rra", operations.rra, fd);
	print_operation("rrb", operations.rrb, fd);
	print_operation("rrr", operations.rrr, fd);
	ft_putendl_fd("", fd);
}

static void	print_strategy(t_bench bench, int fd)
{
	ft_putstr_fd("[bench] strategy:  ", fd);
	ft_putstr_fd(bench.strategy, fd);
	ft_putstr_fd(" / ", fd);
	ft_putendl_fd(bench.complexity, fd);
}

static void	print_disorder(t_bench bench, int fd)
{
	double	percentage;
	int		integer_part;
	int		decimal_part;

	percentage = bench.disorder * 100.0;
	integer_part = (int)percentage;
	decimal_part = (int)((percentage - integer_part) * 100);
	if (decimal_part < 0)
		decimal_part = -decimal_part;
	ft_putstr_fd("[bench] disorder:  ", fd);
	ft_putnbr_fd(integer_part, fd);
	ft_putstr_fd(".", fd);
	if (decimal_part < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(decimal_part, fd);
	ft_putendl_fd("%", fd);
}

void	print_bench(t_bench bench, t_operations operations)
{
	print_disorder(bench, 2);
	print_strategy(bench, 2);
	print_operations(operations, 2);
}
