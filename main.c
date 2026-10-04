/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:15:17 by siooi             #+#    #+#             */
/*   Updated: 2026/10/03 16:20:22 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(int value, int index)
{
	printf("Value: %i, Index: %i\n", value, index);
}

int	main(int argc, char **argv)
{
	char		**args;
	t_flags		flags;
	t_bench		bench;
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	args = build_args(argv);
	check_args(args);
	init_flags(&flags);
	init_stacks(&stacks);
	parse_args(args, &flags, &stacks);
	init_bench(&bench, flags, stacks.a);
	sort_stacks(&stacks, &bench, flags, 1);
	if (flags.bench)
		print_bench(bench, stacks.operations);
	printf("Stack A:\n");
	ft_lstiter(stacks.a, print_stack);
	printf("Stack B:\n");
	ft_lstiter(stacks.b, print_stack);
	free_args(args);
	free_stacks(&stacks);
	return (0);
}
