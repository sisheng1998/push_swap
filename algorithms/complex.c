/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhier <zhier@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:34:31 by zhier             #+#    #+#             */
/*   Updated: 2026/10/12 17:34:33 by zhier            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_pivot(t_list *a, t_list *b, int *p1, int *p2)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	*p1 = size_b + (size_a * 0.35);
	*p2 = size_b + (size_a * 0.65);
}

static void	push_to_b(t_stacks *stacks, int print)
{
	int		p1;
	int		p2;
	t_list	*lst;

	find_pivot(stacks->a, stacks->b, &p1, &p2);
	lst = stacks->a;
	if (lst->index < p2)
	{
		pb(stacks, print);
		if (lst->index < p1 && ft_lstsize(stacks->b) >= 2)
			rb(stacks, print);
	}
	else
		ra(stacks, print);
}

void	quick_sort(t_stacks *stacks, int print)
{
	if (!stacks || is_sorted(stacks->a))
		return ;
	if (ft_lstsize(stacks->a) <= 5)
	{
		fixed_sort(stacks, print);
		return ;
	}
	while (ft_lstsize(stacks->a) > 5)
		push_to_b(stacks, print);
	fixed_sort(stacks, print);
	while (ft_lstsize(stacks->b))
		push_cheapest(stacks, 0, print);
	final_alignment(stacks, print);
}
