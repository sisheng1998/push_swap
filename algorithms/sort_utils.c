/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siooi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:40:30 by siooi             #+#    #+#             */
/*   Updated: 2026/09/27 15:58:42 by siooi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->index < index)
			return (0);
		index = stack->index;
		stack = stack->next;
	}
	return (1);
}
