/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:12:28 by siooi             #+#    #+#             */
/*   Updated: 2026/10/04 17:40:48 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char		**args;
	char		**ops;
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	args = build_args(argv);
	check_args_bonus(args);
	ops = build_operations(0);
	check_operations(args, ops);
	init_stacks(&stacks);
	parse_args_bonus(args, &stacks);
	execute_operations(&stacks, ops);
	if (is_sorted(stacks.a) && !stacks.b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_args(args);
	free_args(ops);
	free_stacks(&stacks);
	return (0);
}
