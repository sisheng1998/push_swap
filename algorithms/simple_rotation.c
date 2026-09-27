/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:19:47 by siooi             #+#    #+#             */
/*   Updated: 2026/09/27 19:08:52 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stacks *stacks, int *cost_a, int *cost_b, int print)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stacks, print);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stacks, print);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_single(t_stacks *stacks, int *cost, char stack, int print)
{
	while (*cost > 0)
	{
		if (stack == 'a')
			ra(stacks, print);
		else
			rb(stacks, print);
		(*cost)--;
	}
	while (*cost < 0)
	{
		if (stack == 'a')
			rra(stacks, print);
		else
			rrb(stacks, print);
		(*cost)++;
	}
}

void	apply_move(t_stacks *stacks, t_move *move, int print)
{
	rotate_both(stacks, &move->cost_a, &move->cost_b, print);
	rotate_single(stacks, &move->cost_a, 'a', print);
	rotate_single(stacks, &move->cost_b, 'b', print);
}
