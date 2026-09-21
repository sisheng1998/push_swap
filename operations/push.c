/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 17:34:00 by siooi             #+#    #+#             */
/*   Updated: 2026/09/20 17:55:24 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!from || !*from || !to)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

void	pa(t_stacks *stacks, int record, int print)
{
	push(&stacks->b, &stacks->a);
	if (print)
		ft_putendl_fd("pa", 1);
	if (record)
	{
		stacks->operations.pa++;
		stacks->operations.total++;
	}
}

void	pb(t_stacks *stacks, int record, int print)
{
	push(&stacks->a, &stacks->b);
	if (print)
		ft_putendl_fd("pb", 1);
	if (record)
	{
		stacks->operations.pb++;
		stacks->operations.total++;
	}
}
