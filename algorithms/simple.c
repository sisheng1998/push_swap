/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:07:28 by siooi             #+#    #+#             */
/*   Updated: 2026/10/03 17:46:17 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheapest(t_stacks *stacks, int to_b, int print)
{
	t_move	move;

	move = get_cheapest_move(stacks, to_b);
	apply_move(stacks, &move, print);
	if (to_b)
		pb(stacks, print);
	else
		pa(stacks, print);
}

void	final_alignment(t_stacks *stacks, int print)
{
	t_move	move;

	move.node = get_min_node(stacks->a);
	move.cost_a = get_rotation_cost(stacks->a, move.node);
	move.cost_b = 0;
	apply_move(stacks, &move, print);
}

void	insertion_sort(t_stacks *stacks, int print)
{
	if (!stacks || is_sorted(stacks->a))
		return ;
	if (ft_lstsize(stacks->a) <= 5)
	{
		fixed_sort(stacks, print);
		return ;
	}
	pb(stacks, print);
	pb(stacks, print);
	while (ft_lstsize(stacks->a) > 3)
		push_cheapest(stacks, 1, print);
	sort_three(stacks, print);
	while (ft_lstsize(stacks->b) > 0)
		push_cheapest(stacks, 0, print);
	final_alignment(stacks, print);
}
