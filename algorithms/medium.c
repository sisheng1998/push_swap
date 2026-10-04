/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 16:22:45 by siooi             #+#    #+#             */
/*   Updated: 2026/10/04 13:50:37 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

static int	calculate_delta(t_list *stack)
{
	int	size;
	int	delta;

	size = ft_lstsize(stack);
	delta = ft_sqrt(size) * 1.5;
	return (delta);
}

static void	apply_k_distribution(t_stacks *stacks, int print)
{
	int	delta;
	int	threshold;

	delta = calculate_delta(stacks->a);
	threshold = 0;
	while (ft_lstsize(stacks->a) > 0)
	{
		if (stacks->a->index <= threshold + delta)
		{
			pb(stacks, print);
			if (ft_lstsize(stacks->b) >= 2 && stacks->b->index <= threshold)
				rb(stacks, print);
			threshold++;
		}
		else
			ra(stacks, print);
	}
}

void	chunk_sort(t_stacks *stacks, int print)
{
	if (!stacks || is_sorted(stacks->a))
		return ;
	if (ft_lstsize(stacks->a) <= 5)
	{
		fixed_sort(stacks, print);
		return ;
	}
	apply_k_distribution(stacks, print);
	while (ft_lstsize(stacks->b) > 0)
		push_cheapest(stacks, 0, print);
	final_alignment(stacks, print);
}
