/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:28:46 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 16:06:39 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min_node(t_list *stack)
{
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min_node = NULL;
	while (stack)
	{
		if (stack->index == -1 && (!min_node || stack->value < min_node->value))
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	assign_index(t_list *stack)
{
	int		index;
	t_list	*min_node;

	if (!stack)
		return ;
	index = 0;
	min_node = get_next_min_node(stack);
	while (min_node)
	{
		min_node->index = index++;
		min_node = get_next_min_node(stack);
	}
}
