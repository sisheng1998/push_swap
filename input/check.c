/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:46:24 by siooi             #+#    #+#             */
/*   Updated: 2026/10/04 16:26:13 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char **args)
{
	if (args)
		free_args(args);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static int	check_exist(char **args, int is_exist)
{
	if (is_exist)
		print_error(args);
	return (1);
}

long	check_number(char **args, char *str)
{
	int		i;
	long	result;

	i = 0;
	if (!str || str[i] == '\0')
		print_error(args);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		print_error(args);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(args);
		i++;
	}
	result = ft_atol(str);
	if (result < -2147483648 || result > 2147483647)
		print_error(args);
	return (result);
}

void	check_duplicate(char **args, int idx, long num)
{
	int		i;
	t_mode	mode;

	i = 0;
	while (i < idx)
	{
		mode = get_mode(args[i]);
		if (mode == DEFAULT && ft_atol(args[i]) == num)
			print_error(args);
		i++;
	}
}

void	check_args(char **args)
{
	int		i;
	int		is_flags;
	int		is_bench;
	t_mode	mode;
	long	num;

	is_flags = 0;
	is_bench = 0;
	i = 0;
	while (args[i])
	{
		mode = get_mode(args[i]);
		if (mode == DEFAULT)
		{
			num = check_number(args, args[i]);
			check_duplicate(args, i, num);
		}
		else if (mode == BENCH)
			is_bench = check_exist(args, is_bench);
		else
			is_flags = check_exist(args, is_flags);
		i++;
	}
}
