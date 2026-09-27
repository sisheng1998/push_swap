/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 17:25:04 by siooi             #+#    #+#             */
/*   Updated: 2026/09/27 19:04:52 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotation_cost(t_list *stack, t_list *target)
{
	int	position;
	int	size;

	position = get_target_position(stack, target);
	size = ft_lstsize(stack);
	if (position <= size / 2)
		return (position);
	return (position - size);
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

static int	get_total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(cost_a);
	abs_b = ft_abs(cost_b);
	if ((cost_a >= 0) == (cost_b >= 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

static t_move	get_move(t_stacks *stacks, t_list *node, int to_b)
{
	t_move	move;

	move.node = node;
	if (to_b)
	{
		move.cost_a = get_rotation_cost(stacks->a, node);
		move.cost_b = get_rotation_cost(stacks->b,
				get_smaller_target(stacks->b, node->index));
	}
	else
	{
		move.cost_a = get_rotation_cost(stacks->a,
				get_larger_target(stacks->a, node->index));
		move.cost_b = get_rotation_cost(stacks->b, node);
	}
	move.total = get_total_cost(move.cost_a, move.cost_b);
	return (move);
}

t_move	get_cheapest_move(t_stacks *stacks, int to_b)
{
	t_list	*current;
	t_move	cheapest;
	t_move	move;

	current = stacks->b;
	if (to_b)
		current = stacks->a;
	cheapest = get_move(stacks, current, to_b);
	current = current->next;
	while (current)
	{
		move = get_move(stacks, current, to_b);
		if (move.total < cheapest.total)
			cheapest = move;
		current = current->next;
	}
	return (cheapest);
}
