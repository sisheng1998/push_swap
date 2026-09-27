/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:44:33 by siooi             #+#    #+#             */
/*   Updated: 2026/09/27 19:17:16 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_smaller_target(t_list *stack, int target_index)
{
	t_list	*current;
	t_list	*target;
	t_list	*fallback;

	if (!stack)
		return (NULL);
	target = NULL;
	fallback = stack;
	current = stack;
	while (current)
	{
		if (current->index > fallback->index)
			fallback = current;
		if (current->index < target_index)
		{
			if (!target || current->index > target->index)
				target = current;
		}
		current = current->next;
	}
	if (!target)
		target = fallback;
	return (target);
}

t_list	*get_larger_target(t_list *stack, int target_index)
{
	t_list	*current;
	t_list	*target;
	t_list	*fallback;

	if (!stack)
		return (NULL);
	target = NULL;
	fallback = stack;
	current = stack;
	while (current)
	{
		if (current->index < fallback->index)
			fallback = current;
		if (current->index > target_index)
		{
			if (!target || current->index < target->index)
				target = current;
		}
		current = current->next;
	}
	if (!target)
		target = fallback;
	return (target);
}

int	get_target_position(t_list *stack, t_list *target)
{
	int	position;

	if (!stack || !target)
		return (0);
	position = 0;
	while (stack)
	{
		if (stack == target)
			return (position);
		stack = stack->next;
		position++;
	}
	return (position);
}

t_list	*get_min_node(t_list *stack)
{
	t_list	*min_node;
	int		index;

	if (!stack)
		return (NULL);
	min_node = stack;
	index = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index < index)
		{
			index = stack->index;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
