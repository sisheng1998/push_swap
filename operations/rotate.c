/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:16:11 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 18:53:15 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stacks *stacks, int record, int print)
{
	rotate(&stacks->a);
	if (print)
		ft_putendl_fd("ra", 1);
	if (record)
	{
		stacks->operations.ra++;
		stacks->operations.total++;
	}
}

void	rb(t_stacks *stacks, int record, int print)
{
	rotate(&stacks->b);
	if (print)
		ft_putendl_fd("rb", 1);
	if (record)
	{
		stacks->operations.rb++;
		stacks->operations.total++;
	}
}

void	rr(t_stacks *stacks, int record, int print)
{
	ra(stacks, 0, 0);
	rb(stacks, 0, 0);
	if (print)
		ft_putendl_fd("rr", 1);
	if (record)
	{
		stacks->operations.rr++;
		stacks->operations.total++;
	}
}
