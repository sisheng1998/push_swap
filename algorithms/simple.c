/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:07:28 by siooi             #+#    #+#             */
/*   Updated: 2026/09/27 18:53:58 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a_to_b(t_stacks *stacks, int print)
{
	t_list	*cheapest;

	cheapest = get_cheapest_a_to_b(stacks);
	rotate_for_push_b(stacks, cheapest, print);
	pb(stacks, print);
}

static void	push_b_to_a(t_stacks *stacks, int print)
{
	t_list	*cheapest;

	cheapest = get_cheapest_b_to_a(stacks);
	rotate_for_push_a(stacks, cheapest, print);
	pa(stacks, print);
}

static void	final_alignment(t_stacks *stacks, int print)
{
	t_list	*min_node;
	int		min_pos;
	int		size;

	min_node = get_min_node(stacks->a);
	size = ft_lstsize(stacks->a);
	while (stacks->a != min_node)
	{
		min_pos = get_target_position(stacks->a, min_node);
		if (min_pos <= size / 2)
			ra(stacks, print);
		else
			rra(stacks, print);
	}
}

void	insertion_sort(t_stacks *stacks, int print)
{
	if (!stacks)
		return ;
	if (ft_lstsize(stacks->a) > 3)
		pb(stacks, print);
	if (ft_lstsize(stacks->a) > 3)
		pb(stacks, print);
	while (ft_lstsize(stacks->a) > 3)
		push_a_to_b(stacks, print);
	sort_three(stacks, print);
	while (ft_lstsize(stacks->b) > 0)
		push_b_to_a(stacks, print);
	final_alignment(stacks, print);
}
