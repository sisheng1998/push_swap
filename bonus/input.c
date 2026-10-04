/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:57:29 by siooi             #+#    #+#             */
/*   Updated: 2026/10/04 18:03:05 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_args_bonus(char **args)
{
	int		i;
	t_mode	mode;
	long	num;

	i = 0;
	while (args[i])
	{
		mode = get_mode(args[i]);
		if (mode == DEFAULT)
		{
			num = check_number(args, args[i]);
			check_duplicate(args, i, num);
		}
		else
			print_error(args);
		i++;
	}
}

void	parse_args_bonus(char **args, t_stacks *stacks)
{
	int		i;

	i = 0;
	while (args[i])
	{
		ft_lstadd_back(&stacks->a, ft_lstnew((int)ft_atol(args[i])));
		i++;
	}
	assign_index(stacks->a);
}

char	**build_operations(int fd)
{
	(void)fd;
	return (NULL);
}

void	check_operations(char **args, char **operations)
{
	(void)args;
	(void)operations;
}

void	execute_operations(t_stacks *stacks, char **operations)
{
	(void)stacks;
	(void)operations;
}
