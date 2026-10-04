/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:21:43 by siooi             #+#    #+#             */
/*   Updated: 2026/10/03 12:58:44 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	compute_disorder(t_list *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*first;
	t_list	*second;

	mistakes = 0;
	total_pairs = 0;
	first = stack;
	while (first)
	{
		second = first->next;
		while (second)
		{
			total_pairs++;
			if (first->index > second->index)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / total_pairs);
}

static void	set_label(t_bench *bench, t_flags flags)
{
	char *const	strategies[] = {"Adaptive", "Simple", "Medium", "Complex"};
	char *const	classes[] = {"Adaptive", "O(n²)", "O(n√n)", "O(n log n)"};

	if (flags.mode >= ADAPTIVE)
		flags.mode = DEFAULT;
	bench->strategy = strategies[flags.mode];
	bench->complexity = classes[flags.mode];
}

void	init_bench(t_bench *bench, t_flags flags, t_list *stack)
{
	bench->disorder = compute_disorder(stack);
	set_label(bench, flags);
}
