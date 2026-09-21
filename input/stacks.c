/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 12:56:37 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 13:34:59 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_operations(t_operations *operations)
{
	operations->sa = 0;
	operations->sb = 0;
	operations->ss = 0;
	operations->pa = 0;
	operations->pb = 0;
	operations->ra = 0;
	operations->rb = 0;
	operations->rr = 0;
	operations->rra = 0;
	operations->rrb = 0;
	operations->rrr = 0;
	operations->total = 0;
}

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	init_operations(&stacks->operations);
}

static void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	free_stack(&stacks->a);
	stacks->a = NULL;
	free_stack(&stacks->b);
	stacks->b = NULL;
}
