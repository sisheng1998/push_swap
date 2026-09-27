/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:13:18 by siooi             #+#    #+#             */
/*   Updated: 2026/09/27 19:20:47 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_sort(t_stacks *stacks, int print)
{
	insertion_sort(stacks, print);
}

void	sort_stacks(t_stacks *stacks, t_flags flags, int print)
{
	int	size;

	size = ft_lstsize(stacks->a);
	if (is_sorted(stacks->a))
		return ;
	else if (size <= 5)
	{
		fixed_sort(stacks, print);
		return ;
	}
	if (flags.mode == SIMPLE)
		insertion_sort(stacks, print);
	else
		adaptive_sort(stacks, print);
	if (is_sorted(stacks->a))
		write(1, "Sorted!\n", 8);
}
