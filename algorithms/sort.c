/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:13:18 by siooi             #+#    #+#             */
/*   Updated: 2026/10/04 11:57:56 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_sort(t_stacks *stacks, t_bench *bench, int print)
{
	if (bench->disorder < 0.2)
	{
		insertion_sort(stacks, print);
		bench->complexity = "O(n²)";
	}
	else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
	{
		chunk_sort(stacks, print);
		bench->complexity = "O(n√n)";
	}
	else
	{
		chunk_sort(stacks, print);
		bench->complexity = "O(n log n)";
	}
}

void	sort_stacks(t_stacks *stacks, t_bench *bench, t_flags flags, int print)
{
	if (flags.mode == SIMPLE)
		insertion_sort(stacks, print);
	else if (flags.mode == MEDIUM)
		chunk_sort(stacks, print);
	else if (flags.mode == COMPLEX)
		chunk_sort(stacks, print);
	else
		adaptive_sort(stacks, bench, print);
	if (is_sorted(stacks->a))
		write(1, "Sorted!\n", 8);
}
