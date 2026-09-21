/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:16:11 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 17:29:50 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
}

void	sa(t_stacks *stacks, int record, int print)
{
	swap(&stacks->a);
	if (print)
		ft_putendl_fd("sa", 1);
	if (record)
	{
		stacks->operations.sa++;
		stacks->operations.total++;
	}
}

void	sb(t_stacks *stacks, int record, int print)
{
	swap(&stacks->b);
	if (print)
		ft_putendl_fd("sb", 1);
	if (record)
	{
		stacks->operations.sb++;
		stacks->operations.total++;
	}
}

void	ss(t_stacks *stacks, int record, int print)
{
	sa(stacks, 0, 0);
	sb(stacks, 0, 0);
	if (print)
		ft_putendl_fd("ss", 1);
	if (record)
	{
		stacks->operations.ss++;
		stacks->operations.total++;
	}
}
