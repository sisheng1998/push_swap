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

static int	find_pivot(t_list *ab)
{
	return (0.35 * ft_lstsize(ab));
}

static void	push_to_b(t_stacks *stacks, int print)
{
	int		p1;
	int		p2;
	t_list	*lst;

	p1 = find_pivot(stacks->a);
	p2 = ft_lstsize(stacks->a) - p1;
	lst = stacks->a;
	if (lst->index < p2)
	{
		pb(stacks, print);
		if (lst->index < p1)
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
