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

int	get_total_cost(t_list *stack, t_list *target_stack,
			t_list *current, t_list *target)
{
	int	cost_stack;
	int	cost_target;
	int	abs_cost_stack;
	int	abs_cost_target;

	cost_stack = get_rotation_cost(stack, current);
	cost_target = get_rotation_cost(target_stack, target);
	abs_cost_stack = ft_abs(cost_stack);
	abs_cost_target = ft_abs(cost_target);
	if ((cost_stack >= 0 && cost_target >= 0)
		|| (cost_stack < 0 && cost_target < 0))
	{
		if (abs_cost_stack > abs_cost_target)
			return (abs_cost_stack);
		return (abs_cost_target);
	}
	return (abs_cost_stack + abs_cost_target);
}

t_list	*get_cheapest_a_to_b(t_stacks *stacks)
{
	t_list	*current;
	t_list	*cheapest;
	t_list	*target;
	int		current_cost;
	int		cheapest_cost;

	current = stacks->a;
	cheapest = stacks->a;
	cheapest_cost = 0;
	while (current)
	{
		target = get_smaller_target(stacks->b, current->index);
		current_cost = get_total_cost(stacks->a, stacks->b, current, target);
		if (current == stacks->a || current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

t_list	*get_cheapest_b_to_a(t_stacks *stacks)
{
	t_list	*current;
	t_list	*cheapest;
	t_list	*target;
	int		current_cost;
	int		cheapest_cost;

	current = stacks->b;
	cheapest = stacks->b;
	cheapest_cost = 0;
	while (current)
	{
		target = get_larger_target(stacks->a, current->index);
		current_cost = get_total_cost(stacks->b, stacks->a, current, target);
		if (current == stacks->b || current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
