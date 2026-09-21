/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:16:11 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 19:32:47 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_second_last_node(t_list *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = get_second_last_node(*stack);
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stacks *stacks, int record, int print)
{
	reverse_rotate(&stacks->a);
	if (print)
		ft_putendl_fd("rra", 1);
	if (record)
	{
		stacks->operations.rra++;
		stacks->operations.total++;
	}
}

void	rrb(t_stacks *stacks, int record, int print)
{
	reverse_rotate(&stacks->b);
	if (print)
		ft_putendl_fd("rrb", 1);
	if (record)
	{
		stacks->operations.rrb++;
		stacks->operations.total++;
	}
}

void	rrr(t_stacks *stacks, int record, int print)
{
	rra(stacks, 0, 0);
	rrb(stacks, 0, 0);
	if (print)
		ft_putendl_fd("rrr", 1);
	if (record)
	{
		stacks->operations.rrr++;
		stacks->operations.total++;
	}
}
