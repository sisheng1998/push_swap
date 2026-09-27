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

void	rotate_for_push_b(t_stacks *stacks, t_list *cheapest, int print)
{
	t_list	*target;
	int		cost_a;
	int		cost_b;

	target = get_smaller_target(stacks->b, cheapest->index);
	cost_a = get_rotation_cost(stacks->a, cheapest);
	cost_b = get_rotation_cost(stacks->b, target);
	rotate_both(stacks, &cost_a, &cost_b, print);
	rotate_single(stacks, &cost_a, 'a', print);
	rotate_single(stacks, &cost_b, 'b', print);
}

void	rotate_for_push_a(t_stacks *stacks, t_list *cheapest, int print)
{
	t_list	*target;
	int		cost_a;
	int		cost_b;

	target = get_larger_target(stacks->a, cheapest->index);
	cost_a = get_rotation_cost(stacks->a, target);
	cost_b = get_rotation_cost(stacks->b, cheapest);
	rotate_both(stacks, &cost_a, &cost_b, print);
	rotate_single(stacks, &cost_a, 'a', print);
	rotate_single(stacks, &cost_b, 'b', print);
}
