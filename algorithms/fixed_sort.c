/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:47:33 by siooi             #+#    #+#             */
/*   Updated: 2026/09/27 16:28:26 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_list *stack, int *index, int is_max)
{
	int	position;
	int	current_pos;

	if (!stack)
	{
		*index = 0;
		return (0);
	}
	position = 0;
	current_pos = 1;
	*index = stack->index;
	stack = stack->next;
	while (stack)
	{
		if ((is_max && stack->index > *index)
			|| (!is_max && stack->index < *index))
		{
			*index = stack->index;
			position = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (position);
}

static void	sort_two(t_stacks *stacks, int print)
{
	if (stacks->a->index > stacks->a->next->index)
		sa(stacks, print);
}

void	sort_three(t_stacks *stacks, int print)
{
	int	max_index;
	int	max_pos;

	max_pos = get_position(stacks->a, &max_index, 1);
	if (max_pos == 0)
		ra(stacks, print);
	else if (max_pos == 1)
		rra(stacks, print);
	sort_two(stacks, print);
}

static void	sort_five(t_stacks *stacks, int size, int print)
{
	int	min_index;
	int	min_pos;
	int	count;

	count = 0;
	while (size > 3)
	{
		min_pos = get_position(stacks->a, &min_index, 0);
		while (stacks->a->index != min_index)
		{
			if (min_pos <= size / 2)
				ra(stacks, print);
			else
				rra(stacks, print);
		}
		pb(stacks, print);
		size--;
		count++;
	}
	sort_three(stacks, print);
	while (count > 0)
	{
		pa(stacks, print);
		count--;
	}
}

void	fixed_sort(t_stacks *stacks, int print)
{
	int	size;

	size = ft_lstsize(stacks->a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(stacks, print);
	else if (size == 3)
		sort_three(stacks, print);
	else
		sort_five(stacks, size, print);
}
